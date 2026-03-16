#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vi c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<vi> dp(n, vi(n, 0));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for (int i = 0; i < n-1; i++) {
        dp[i][i+1] = 1 + (c[i] != c[i+1]);
    }

    for (int l = 3; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;

            dp[i][j] = INT_MAX;
            if (c[i] == c[j]) {
                dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
            }

            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }

    cout << dp[0][n-1];
}