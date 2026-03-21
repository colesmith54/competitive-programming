#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, c, k;
    cin >> n >> c >> k;
    
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    
    sort(a.begin(), a.end());
    
    for (ll x : a) {
        ll d = max(min(c - x, k), 0LL);
        k -= d;
        x += d;
        
        if (x <= c) {
            c += x;
        } else {
            break;
        }
    }
    
    cout << c << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
