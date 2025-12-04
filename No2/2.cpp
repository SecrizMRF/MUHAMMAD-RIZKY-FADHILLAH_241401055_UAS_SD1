#include <iostream>
#include <cmath>
using namespace std;

// terimagajieh Kak, awak tinggal modif kode dari kakak kemarin xixixi
int Interpolation (int arr[], int n, int nokur) {
    int high = n-1;
    int low = 0;

    while (low <= high && nokur >= arr[low] && nokur <= arr[high]) {
        if (low == high) {
            if (arr[low] == nokur) return low;
            return -1;
        }
        int pos = low + ((nokur - arr[low]) * (high - low)) / (arr[high] - arr[low]); 
        if (arr[pos] == nokur) return pos;
        if (arr[pos] < nokur) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    system("cls");
    int n, nokur, ulang;

    do {
        system("cls");
        cout << "Jumlah kursi yang tersedia: "; cin >> n;

        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        //  input si nomor kursi yang mau dicari
        cout << "Nomor yang ingin dicari: "; cin >> nokur;
        cout << "\nMencari kursi Nomor: " << nokur << endl;

        int id = Interpolation(arr, n, nokur);
        if (id != -1) {
            cout << "Status: TERSEDIA" << endl;
            cout << "Detail: Ditemukan pada index [" << id << "]" << endl;
        } else {
            cout << "Status: TIDAK TERSEDIA" << endl;
            int low = 0, high = n-1;

            while (low <= high && nokur >= arr[low] && nokur <= arr[high]) {
                int pos = low + ((nokur - arr[low]) * (high - low)) / (arr[high] - arr[low]);
                if (arr[pos] < nokur) low = pos + 1;
                else high = pos - 1;
            }

            int left = (high >= 0) ? arr[high] : -1;
            int right = (low < n) ? arr[low] : -1;

            cout << "Opsi : Kursi terdekat yang tersedia adalah No. ";
            if (left == -1) cout << right << endl;
            else if (right == -1) cout << left << endl;
            else {
                if (abs (nokur - left) <= abs (nokur - right)) cout << left << endl;
                else cout << right << endl;
            }
        }

        cout << "Mau ulang program? (1 (ya)/ 2 (tidak)): "; cin >> ulang;
        cin.ignore();
    } while (ulang != 2);
    return 0;
}