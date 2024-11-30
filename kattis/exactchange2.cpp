// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

void solve() {
    int price, n;
    cin >> price >> n;

    vi coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    int limit = accumulate(coins.begin(), coins.end(), 0);
    vi dp(limit + 1, limit + 1);
    dp[0] = 0;

    for (const int coin : coins) {
        for (int j = limit; j >= coin; j--) {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    int total;
    for (total = price; total <= limit; total++) {
        if (dp[total] <= limit) break;
    }

    cout << total << ' ' << dp[total] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}