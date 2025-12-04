#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <limits>
#include <stack>
using namespace std;

const int INF = INT_MAX;

struct Node {
    int kota;
    int jarak;
    bool operator>(const Node& other) const {
        return jarak > other.jarak;
    }
};

// Fungsi Dijkstra
void dijkstra(const vector<vector<int>>& graph, int start, int goal,
              const vector<string>& kota) {
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        int u = pq.top().kota;
        int d = pq.top().jarak;
        pq.pop();

        if (d > dist[u]) continue; // skip jika jarak sudah lebih baik
        if (u == goal) break; // sudah sampai tujuan

        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0) { // ada jalur
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    parent[v] = u;
                    pq.push({v, newDist});
                }
            }
        }
    }

    if (dist[goal] == INF) {
        cout << "Tidak ada rute dari " << kota[start] << " ke " << kota[goal] << ".\n";
        return;
    }

    // Rekonstruksi jalur
    stack<int> path;
    for (int v = goal; v != -1; v = parent[v]) {
        path.push(v);
    }

    cout << "=== (DIJKSTRA - RUTE TERPENDEK) ===\n\n";
    cout << "Rute terbaik:\n";
    while (!path.empty()) {
        cout << kota[path.top()];
        path.pop();
        if (!path.empty()) cout << " -> ";
    }

    cout << "\n\nTotal jarak minimum: " << dist[goal] << " km\n";
}

int main() {
    system("cls");
    vector<string> kota = {
        "Medan",
        "Tebing Tinggi",
        "Berastagi",
        "Pematangsiantar",
        "Sidikalang",
        "Parapat"
    };

    int n = kota.size();

    // Matriks jarak antar kota (0 = tidak ada jalur langsung)
    vector<vector<int>> graph = {
        // medan, tt, brst, ptgsi, sdkl, prpt
        {0, 70, 60, 0, 0, 0},   // Medan
        {70, 0, 0, 50, 0, 0},   // tt
        {60, 0, 0, 80, 90, 0},   // berastagi
        {0, 50, 80, 0, 65, 45}, // Pematangsiantar
        {0, 0, 90, 65, 0, 120},   // sidikalang
        {0, 0, 0, 45, 120, 0},   // parapat
    };

    cout << "Kota yang tersedia: ";
    for(int i = 0; i < n; i++){
        cout << kota[i] << ", ";
    }
    cout << endl;

    string asal;
    cout << "Masukkan kota asal: ";
    getline(cin, asal);
    
    string tujuan;
    cout << "Masukkan kota tujuan: ";
    getline(cin, tujuan);

    int start = -1, goal = -1;
    for (int i = 0; i < n; i++) {
        if (kota[i] == asal) start = i;
        if (kota[i] == tujuan) goal = i;
    }

    if (start == -1 || goal == -1) {
        cout << "Kota asal atau tujuan tidak ditemukan!\n";
        return 1;
    }

    dijkstra(graph, start, goal, kota);
    return 0;
}