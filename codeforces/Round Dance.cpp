// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<set<int>> g(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        g[i].insert(a[i]);
        g[a[i]].insert(i);
    }

    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = (int)g[i].size();
    }

    vector<bool> vis(n, false);
    int bamboos = 0, cycles = 0;

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;

        queue<int> q;
        q.push(i);
        vis[i] = true;
        vector<int> component = {i};

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (vis[v]) continue;
                vis[v] = true;
                q.push(v);
                component.push_back(v);
            }
        }

        bool bamboo = false;
        for (int j : component) {
            if (d[j] == 1) {
                bamboo = true;
                break;
            }
        }

        if (bamboo) {
            bamboos++;
        } else {
            cycles++;
        }
    }

    cout << (cycles + min(bamboos, 1)) << ' ' << (cycles + bamboos) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}