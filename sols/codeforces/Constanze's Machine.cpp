#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    long long mod = 1e9 + 7;
    vector<long long> dp(1e5 + 1, 1);
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= 1e5; ++i) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % mod;
    }

    long long ans = 1;
    int run = 0;
    char curr = '~';

    for (char c : s) {
        if (c == 'm' || c == 'w') {
            cout << "0";
            return;
        }

        if (c == 'u' || c == 'n') {
            if (c == curr) {
                ++run;
            } else {
                ans = (ans * dp[run]) % mod;
                run = 1;
            }
        } else {
            ans = (ans * dp[run]) % mod;
            run = 0;
        }
        curr = c;
    }

    ans = (ans * dp[run]) % mod;
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}