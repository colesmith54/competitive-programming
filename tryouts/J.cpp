#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> g(n + 1, vector<char>(n + 1, 0));
    
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
    
    bool rail = g[1][n];
    vector<char> seen(n + 1, 0);

    queue<int> q;
    q.push(1);
    seen[1] = 1;

    int l = 1;

    while (!q.empty()) {
        int sz = q.size();

        while (sz--) {
            int u = q.front();
            q.pop();

            for (int v = 1; v <= n; ++v) {
                if (!seen[v] && (g[u][v] ^ rail)) {
                    if (v == n) {
                        cout << l;
                        return;
                    }

                    seen[v] = 1;
                    q.push(v);
                }
            }
        }

        ++l;
    }
    
    cout << "-1";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}