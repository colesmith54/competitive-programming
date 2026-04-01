#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<ll> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    
    int ans = 0;
    if (a[0] != gcd(a[0], a[1])) ++ans;
    if (a[n - 1] != gcd(a[n - 2], a[n - 1])) ++ans;
    
    for (int i = 1; i < n - 1; ++i) {
        ll t = lcm(gcd(a[i - 1], a[i]), gcd(a[i], a[i + 1]));
        if (a[i] > t) ++ans;
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