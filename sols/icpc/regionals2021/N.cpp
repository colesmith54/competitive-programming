#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto end = lower_bound(a.begin() + j + 1, a.end(), a[i] + a[j]);
            int k = end - (a.begin() + j + 1);
            ans += (1LL << k) - 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}