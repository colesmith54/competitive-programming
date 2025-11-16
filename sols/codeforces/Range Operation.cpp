#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }

    ll best_thingy = LLONG_MIN;
    ll best_d = LLONG_MIN;

    for (ll i = 1; i <= n; ++i) {
        ll thingy = -(i * i) + i + pre[i - 1];
        best_thingy = max(best_thingy, thingy);

        ll other = (i * i) + i - pre[i];
        ll cand = best_thingy + other;
        best_d = max(best_d, cand);
    }

    cout << pre[n] + best_d << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}