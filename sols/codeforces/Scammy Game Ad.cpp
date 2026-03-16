#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<char>> op(n + 1, vector<char>(2));
    vector<vector<ll>> val(n + 1, vector<ll>(2));

    for (int i = 1; i <= n; i++) {
        char op1, op2;
        ll v1, v2;

        cin >> op1 >> v1 >> op2 >> v2;

        op[i][0] = op1;
        op[i][1] = op2;

        val[i][0] = v1;
        val[i][1] = v2;
    }

    vector<vector<ll>> dp(n + 2, vector<ll>(2, 0));
    dp[n + 1][0] = 1;
    dp[n + 1][1] = 1;

    for (int i = n; i >= 1; i--) {
        ll bestNext = max(dp[i + 1][0], dp[i + 1][1]);

        if (op[i][0] == 'x') {
            dp[i][0] = dp[i + 1][0] + (val[i][0] - 1) * bestNext;
        } else {
            dp[i][0] = dp[i + 1][0];
        }

        if (op[i][1] == 'x') {
            dp[i][1] = dp[i + 1][1] + (val[i][1] - 1) * bestNext;
        } else {
            dp[i][1] = dp[i + 1][1];
        }
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        ll sumPlus = 0;

        if (op[i][0] == '+') {
            sumPlus += val[i][0];
        }

        if (op[i][1] == '+') {
            sumPlus += val[i][1];
        }

        ll bestNext = max(dp[i + 1][0], dp[i + 1][1]);
        ans += sumPlus * bestNext;
    }

    ans += dp[1][0];
    ans += dp[1][1];

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}