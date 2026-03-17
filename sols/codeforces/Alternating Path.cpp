#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> g(n + 1);
    
    int x, y;
    while (m--) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    // -1 -> pending
    // 0 -> red
    // 1 -> blue
    // 2 -> not bipartite
    
    vector<int> state(n + 1, -1);
    
    auto dfs = [&](int st) {
        stack<int> stk;
        stk.push(st);
        state[st] = 0;
        
        vector<int> component;
        bool bipartite = true;
        
        while (!stk.empty()) {
            int u = stk.top();
            stk.pop();
            
            component.push_back(u);
            
            for (int v : g[u]) {
                if (state[v] == -1) {
                    state[v] = 1 - state[u];
                    stk.push(v);
                } else {
                    if (state[v] == state[u]) {
                        bipartite = false;
                    }
                }
            }
        }
        
        return make_pair(component, bipartite);
    };
    
    int ans = 0;
    
    for (int i = 1; i <= n; ++i) {
        if (state[i] != -1) continue;
        auto [component, connected] = dfs(i);
        if (!connected) {
            for (int u : component) {
                state[u] = 2;
            }
        } else {
            int red = 0;
            int blue = 0;
            
            for (int u : component) {
                red += state[u] == 0;
                blue += state[u] == 1;
            }
            
            ans += max(red, blue);
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}