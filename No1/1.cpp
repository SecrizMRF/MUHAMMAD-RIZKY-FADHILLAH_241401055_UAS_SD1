#include <iostream>
#include <vector>
using namespace std;

int max_level = 0;
vector<int> karyawan[1111];

// debug, lupa buat rekursif
// update: done cuy
void dfs(int node, int level) {
    max_level = max(max_level, level);
    for (int temp : karyawan[node]) {
        dfs(temp, level + 1);
    }
}

int main() {
    int n, ulang; 
    do {
        system("cls");
        cout<< "Masukkan jumlah karyawan: "; cin >> n;
        cin.ignore();

        vector<int> manager(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> manager[i];
            if (manager[i] != -1) karyawan[manager[i]].push_back(i);
        }

        for (int i = 1; i <= n; i++) {
            if (manager[i] == -1) dfs(i, 1);
        }

        cout << "\nJumlah minimum grup yang dibentuk: " << max_level << endl;
        
        cout << "Mau ulang programnya? (1 (ya)/ 2 (tidak)): ";
        cin >> ulang;
        cin.ignore();

        if(ulang == 2) cout << "Terima kasih telah mencoba program saya!";
    } while (ulang != 2);
}