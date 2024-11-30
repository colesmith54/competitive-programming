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
    int m;
    cin >> m;

    vi tiles(m);
    for (int i = 0; i < m; i++) cin >> tiles[i];

    int n, t;
    cin >> n >> t;

    vvi dp(n + 1, vi(t + 1, 0));
    dp[0][0] = 1;

    for (const int tile : tiles) {
        for (int k = n; k >= 1; k--) {
            for (int s = t; s >= tile; s--) {
                dp[k][s] += dp[k-1][s-tile];
            }
        }
    }

    ll total = 1;
    for (int i = 1; i <= n; i++) {
        total = total * (m - i + 1) / i;
    }

    int wins = dp[n][t];
    int losses = total - wins;

    cout << wins << " : " << losses << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int g;
    cin >> g;

    for (int i = 1; i <= g; i++) {
        cout << "Game " << to_string(i) << " -- ";
        solve();
    }
}