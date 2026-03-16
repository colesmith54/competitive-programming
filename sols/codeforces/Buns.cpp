#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    
    vector<int> a(m), b(m), c(m), d(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(m, 0));
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k * c[j] <= i && k * b[j] <= a[j]; ++k) {
                dp[i][j] = max(dp[i][j], (j == 0 ? 0 : dp[i - k * c[j]][j - 1]) + k * d[j]);
            }
        }
    }
    
    int ans = 0;
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = max(ans, dp[i][j] + q * ((n - i) / p));
        }
    }
    
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}