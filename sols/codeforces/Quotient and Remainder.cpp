#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    ll n, k;
    cin >> n >> k;

    vector<int> q(n);
    for (auto& x : q) cin >> x;

    multiset<ll> r;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        r.insert(x);
    }

    sort(q.begin(), q.end());
    // x = q[i]y + r[i] <= k (y > r[i])
    // r[i] <= k - q[i]y
    //      <= k - q[i](r[i] - 1)
    //      <= k - q[i]r[i] - q[i]
    // r[i] + q[i]r[i] <= k - q[i]
    // r[i] <= (k - q[i]) / (1 + q[i])

    int ans = 0;
    for (auto& qi : q) {
        ll maximum = (k - qi) / (1 + qi);
        auto it = r.upper_bound(maximum);

        if (it != r.begin()) {
            ++ans;
            r.erase(--it);
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}