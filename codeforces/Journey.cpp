#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    vector<double> prob(n + 1, 0);
    prob[1] = 1;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> vis(n + 1, false);
    vis[1] = true;

    queue<int> q;
    q.push(1);

    double ans;
    int lvl = 0;

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int u = q.front();
            q.pop();
            vector<int> children;

            for (int v: g[u]) {
                if (!vis[v]) {
                    children.push_back(v);
                    q.push(v);
                    vis[v] = true;
                }
            }

            if (children.empty()) {
                ans += prob[u] * lvl;
            } else {
                double np = prob[u] / children.size();
                for (int v: children) {
                    prob[v] = np;
                }
            }
        }
        lvl++;
    }

    cout << std::fixed << std::setprecision(15) << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}