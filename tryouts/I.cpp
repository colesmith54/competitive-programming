#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> cnt(m, n / m);
    for (int r = 1; r <= n % m; ++r) {
        ++cnt[r];
    }

    ll ans = 0;
    for (ll a = 0; a < m; ++a) {
        for (ll b = 0; b < m; ++b) {
            if ((a * a + b * b) % m == 0) {
                ans += cnt[a] * cnt[b];
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}