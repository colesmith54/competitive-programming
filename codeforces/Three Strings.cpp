// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++) dp[i][0] = dp[i-1][0] + (a[i-1] != c[i-1]);
    for (int j = 1; j <= n; j++) dp[0][j] = dp[0][j-1] + (b[j-1] != c[j-1]);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = min(
                    dp[i-1][j] + (a[i-1] != c[i+j-1]),
                    dp[i][j-1] + (b[j-1] != c[i+j-1])
            );
        }
    }

    cout << dp[m][n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}