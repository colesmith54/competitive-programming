// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    n = min(n, 50);

    vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
    int u, v;

    while (m--) {
        cin >> u >> v;
        if (u > n || v > n) continue;
        adj[u][v] = adj[v][u] = true;
    }

    int friends1, friends2, friends3, friends4;
    for (int a = 1; a <= n; a++) {
        for (int b = a + 1; b <= n; b++) {
            friends1 = adj[a][b];

            for (int c = b + 1; c <= n; c++) {
                friends2 = friends1 + adj[a][c] + adj[b][c];
                if (friends2 != 0 && friends2 != 3) continue;

                for (int d = c + 1; d <= n; d++) {
                    friends3 = friends2 + adj[a][d] + adj[b][d] + adj[c][d];
                    if (friends3 != 0 && friends3 != 6) continue;

                    for (int e = d + 1; e <= n; e++) {
                        friends4 = friends3 + adj[a][e] + adj[b][e] + adj[c][e] + adj[d][e];
                        if (friends4 != 0 && friends4 != 10) continue;

                        cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e;
                        return 0;
                    }
                }
            }
        }
    }

    cout << -1;
}