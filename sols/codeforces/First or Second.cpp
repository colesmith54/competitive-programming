#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    vector<ll> p(n), s(n);
    p[0] = 0; p[1] = a[0];
    s.back() = 0;
    
    for (int i = 2; i < n; ++i) {
        p[i] = p[i - 1] + abs(a[i - 1]);
    }
    
    for (int i = n - 2; i >= 0; --i) {
        s[i] = s[i + 1] - a[i + 1];
    }
    
    ll ans = -1e18;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, p[i] + s[i]);
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