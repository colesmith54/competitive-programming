// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;

    ll total = 0;
    vector<ll> a(n);
    for (auto& i : a) {
        cin >> i;
        total += i;
    }

    sort(a.begin(), a.end());
    ll ans = 0;

    for (ll j = 1; j < n; j++) {
        ll lower = total - a[j] - y;
        ll upper = total - a[j] - x;

        ll posL = lower_bound(a.begin(), a.begin() + j, lower) - a.begin();
        ll posR = upper_bound(a.begin(), a.begin() + j, upper) - a.begin();

        ans += posR - posL;
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