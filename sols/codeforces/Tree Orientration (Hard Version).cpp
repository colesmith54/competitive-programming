#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> p, r;
public:
    DSU(int n) {
        p.resize(n); iota(p.begin(), p.end(), 0);
        r.assign(n, 0);
    }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

    bool unite(int x, int y) {
        int u = find(x), v = find(y);
        if (u == v) return false;
        if (r[u] > r[v]) swap(u, v);
        else if (r[u] == r[v]) ++r[v];
        p[u] = v;
        return true;
    }
};

void solve() {
    int n; cin >> n;

    vector<string> s(n);
    
    vector<pair<int, int>> e;
    e.reserve(n * n);
    
    vector<int> out(n, 0);
    
    bool oops = false;

    for (int i = 0; i < n; ++i) {
        s[i].reserve(n);
        cin >> s[i];
        
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '1') {
                e.emplace_back(i, j); ++out[i];
                if (i > j && s[j][i] == '1') oops = true;
            }
        }
    }
    
    if (oops) { cout << "No\n"; return; }
    sort(e.begin(), e.end(), [&](auto& a, auto& b) { return out[a.first] == out[b.first] ? out[a.second] > out[b.second] : out[a.first] < out[b.first]; });

    DSU d(n);
    vector<pair<int, int>> ans;
    
    for (auto& [u, v] : e) if (d.unite(u, v)) ans.emplace_back(u, v);
    if (ans.size() != n - 1) { cout << "No\n"; return; }
    
    vector<vector<int>> adj(n);
    for (auto& [u, v] : ans) adj[u].push_back(v);
    
    string m;
    stack<int> stk;
    
    auto dfs = [&m, &stk, &n, &adj](int st) -> string {
        m.assign(n, '0');
        stk.push(st);
        while (!stk.empty()) {
            int u = stk.top(); stk.pop();
            m[u] = '1';
            for (int v : adj[u]) stk.push(v);
        }
        return m;
    };
    
    for (int i = 0; i < n; ++i) { if (dfs(i) != s[i]) { cout << "No\n"; return; }}
    
    cout << "Yes\n";
    for (auto& [u, v] : ans) cout << (u + 1) << ' ' << (v + 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}