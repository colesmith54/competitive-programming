#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    s = '?' + s;
    // 0 = a...a
    // 1 = a...b
    // 2 = b...a
    // 3 = b...b
    
    vector<vector<char>> dp(n + 1, vector<char>(4, 0));
    if (n % 2) dp[0][0] = 1;
    else dp[0][1] = 1;
    
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'a') {
            dp[i][1] = dp[i - 1][0];
            dp[i][2] = dp[i - 1][0];
            dp[i][3] = dp[i - 1][1] || dp[i - 1][2];
        } else if (s[i] == 'b') {
            dp[i][1] = dp[i - 1][3];
            dp[i][2] = dp[i - 1][3];
            dp[i][0] = dp[i - 1][1] || dp[i - 1][2];
        } else {
            dp[i][1] = dp[i - 1][0] || dp[i - 1][3];
            dp[i][2] = dp[i - 1][0] || dp[i - 1][3];
            dp[i][3] = dp[i - 1][1] || dp[i - 1][2];
            dp[i][0] = dp[i - 1][1] || dp[i - 1][2];
        }
    }
    
    if (dp[n][0] || dp[n][1] || dp[n][2] || dp[n][3]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}