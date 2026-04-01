#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node {
    int l = 0;
    int r = 0;
    int p = 0;
};

void solve() {
    int n;
    cin >> n;
    
    int mod = 1e9 + 7;
    vector<int> l(n + 1, 0);
    vector<int> r(n + 1, 0);
    l[0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        int lc, rc;
        cin >> lc >> rc;
        
        l[i] = lc;
        r[i] = rc;
    }
    
    vector<ll> dp(n + 1, 0);
    auto dfs1 = [&](auto&& f, int u) {
        if (!u || !l[u]) {
            dp[u] = 1;
            return;
        }
        
        f(f, l[u]);
        f(f, r[u]);
        dp[u] = (dp[l[u]] + dp[r[u]] + 3) % mod;
    };
    
    dfs1(dfs1, 1);
    
    
    auto dfs2 = [&](auto&& f, int u) {
        if (!u || !l[u]) return;
        dp[l[u]] = (dp[u] + dp[l[u]]) % mod;
        dp[r[u]] = (dp[u] + dp[r[u]]) % mod;
        f(f, l[u]);
        f(f, r[u]);
    };
    
    dfs2(dfs2, 1);
    
    for (int i = 1; i <= n; ++i) {
        cout << dp[i] << ' ';
    }
    
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}