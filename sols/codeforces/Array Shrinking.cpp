#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    vector<vector<int>> dp(n, vector<int>(n, -1));
    
    for (int i = 0; i < n; ++i) {
        dp[i][i] = a[i];
    }
    
    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i <= n - l; ++i) {
            int j = i + l - 1;
            for (int k = i; k < j; ++k) {
                if (dp[i][k] != -1 && dp[i][k] == dp[k + 1][j]) {
                    dp[i][j] = dp[i][k] + 1;
                }
            }
        }
    }
    
    vector<int> dp2(n);
    
    for (int i = 0; i < n; ++i) {
        dp2[i] = i + 1;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (dp[j][i] != -1) {
                dp2[i] = j == 0 ? 1 : min(dp2[i], dp2[j - 1] + 1);
            }
        }
    }
    
    cout << dp2[n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}