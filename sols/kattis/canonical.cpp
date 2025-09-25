// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vi coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    sort(coins.begin(), coins.end(), greater<int>());

    int limit = coins[0] + coins[1];
    vi dp(limit + 1, limit + 1);
    dp[0] = 0;

    for (const int coin : coins) {
        for (int j = coin; j <= limit; j++) {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    auto greedy = [&](int amount) {
        int count = 0;
        for (const int coin : coins) {
            if (coin <= amount) {
                count += amount / coin;
                amount %= coin;
            }
            if (amount == 0) break;
        }
        return count;
    };

    for (int j = 1; j <= limit; j++) {
        if (dp[j] < greedy(j)) {
            cout << "non-canonical";
            return 0;
        }
    }

    cout << "canonical";
}