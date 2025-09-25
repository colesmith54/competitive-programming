// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int invalid() {
    cout << -1;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> ops(n);
    vector<vector<int>> type(4);

    for (int i = 0; i < n; i++) {
        string tp, res;
        cin >> tp >> res;

        int val = 1;
        if (res == "false") val++;
        if (tp == "unset") val += 2;
        ops[i] = val % 4;
        type[val % 4].push_back(i);
    }

    int m;
    cin >> m;

    vector<vector<int>> g(n);
    vector<int> ind(n, 0);

    while (m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        ind[b]++;
    }

    queue<int> q;
    vector<int> ans;
    set<int> seen;

    auto topo = [&](const int op) {
        for (int u : type[op % 4]) {
            if (!ind[u]) {
                if (op == 4 && seen.count(u)) continue;
                q.push(u);
            }
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            ans.push_back(u);
            if (op == 0) seen.insert(u);
            for (int v : g[u]) {
                if (!--ind[v] && ops[v] == op) {
                    q.push(v);
                }
            }
        }
    };

    auto other = [&](const int op) {
        if (type[op].size() > 1) return invalid();
        if (!type[op].empty()) {
            int t = type[op][0];
            if (ind[t]) return invalid();
            ans.push_back(t);
            for (int v: g[t]) ind[v]--;
        } else if (ans.size() != n) {
            return invalid();
        }
    };

    topo(0);
    other(1);
    topo(2);
    other(3);
    topo(4);

    if (ans.size() != n) return invalid();
    for (auto& x : ans) cout << x + 1 << ' ';
}