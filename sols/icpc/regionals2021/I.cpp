#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> g(k + 1, vector<int>(k + 1, 0));
    
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        
        for (int l = 0; l < k; ++l) {
            for (int r = l + 1; r < k; ++r) {
                ++g[t[l] - 'A'][t[r] - 'A'];
            }
        }
    }
    
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (g[i][j] != n) {
                g[i][j] = 0;
            }
        }
    }
    
    vector<int> dp(k, -1);
    int ans = 0;
    
    function<int(int)> dfs = [&](int u) {
        if (dp[u] != -1) return dp[u];
        dp[u] = 1;
        
        for (int v = 0; v < k; ++v) {
            if (g[u][v]) {
                dp[u] = max(dp[u], 1 + dfs(v));
            }
        }
        
        return dp[u];
    };
    
    for (int i = 0; i < k; ++i) {
        ans = max(ans, dfs(i));
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}