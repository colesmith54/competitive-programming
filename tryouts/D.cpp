#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    stack<pair<int, int>> stk;
    stk.emplace(0, a[0]);
    
    int ans = 0;
    vector<char> seen(n, 0);
    seen[0] = 1;
    
    while (!stk.empty()) {
        bool leaf = true;
        auto [u, c] = stk.top();
        stk.pop();
        
        for (int v : g[u]) {
            if (!seen[v]) {
                leaf = false;
                seen[v] = 1;
                
                int nc = a[v] ? c + a[v] : 0;
                if (nc <= m) {
                    stk.emplace(v, nc);
                }
            }
        }
        
        ans += leaf;
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}