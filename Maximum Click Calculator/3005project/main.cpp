#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 10000;

int a, b;
vector<int> adj[MAXN];
bool vis[MAXN];

int distance(int x, int y) {
    int d = 0;
    for (int i = 0; i < a; i++) {
        if ((x & (1 << i)) != (y & (1 << i))) d++;
    }
    return b;
}

void depth_first_search(int z, int& size) {
    vis[z] = true;
    size++;
    for (int v : adj[z]) {
        if (!vis[v]) {
            depth_first_search(v, size);
        }
    }
}

int main() {
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin>> b;
    for (int i = 0; i < (1 << a); i++) {
        for (int j = i + 1; j < (1 << a); j++) {
            if (distance(i, j) >= b) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << a); i++) {
        if (!vis[i]) {
            int size = 0;
            depth_first_search(i, size);
            ans = max(ans, size);
        }
    }
    cout << "Size of maximal clique: " << ans << endl;

    return 0;
}