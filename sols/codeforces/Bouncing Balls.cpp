#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

void solve() {
    ll n, p, k, x, y;
    string a;
    cin >> n >> p >> k >> a >> x >> y;

    vector<ll> empty(n-p+1, 0);
    for (ll i = n-p; i >= 0; i--) {
        empty[i] = (a[i+p-1] == '0');
        if (i+k <= n-p) empty[i] += empty[i+k];
    }

    ll ans = LLONG_MAX;
    for (ll i = 0; i <= n-p; i++) {
        ans = min(ans, x * empty[i] + y * i);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}