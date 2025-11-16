#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> g(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> seen(n + 1, false);
    vector<int> d(k + 1, 0);

    queue<int> q;
    q.push(1);
    seen[1] = true;

    int lvl = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int u = q.front();
            q.pop();

            d[a[u]] = max(d[a[u]], lvl);

            for (int v : g[u]) {
                if (!seen[v]) {
                    q.push(v);
                    seen[v] = true;
                }
            }
        }
        ++lvl;
    }

    for (int i = 1; i <= k; ++i) {
        cout << d[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}