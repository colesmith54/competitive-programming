#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll x, y;
    cin >> x >> y;
    
    // 0 = x
    // 1 = y
    vector<ll> reflect;
    
    while ((x > 3 || y > 3) && abs(x - y) > 1) {
        ll pos = 63 - __builtin_clzll(max(x, y));
        ll a = x >> pos & 1;
        ll b = y >> pos & 1;
        
        if (a && b) {
            x = x & ~(1LL << pos);
            y = y & ~(1LL << pos);
        } else if (a) {
            reflect.push_back(0);
            ll d = x - (1LL << pos);
            x = x - (2 * d) - 1;
        } else if (b) {
            reflect.push_back(1);
            ll d = y - (1LL << pos);
            y = y - (2 * d) - 1;
        }
    }
    
    map<pair<ll, ll>, ll> m = {
        {{0, 0}, 0},
        {{1, 0}, 0},
        {{2, 0}, 3},
        {{3, 0}, 3},
        {{0, 1}, 0},
        {{1, 1}, 0},
        {{2, 1}, 0},
        {{3, 1}, 3},
        {{0, 2}, 1},
        {{1, 2}, 0},
        {{2, 2}, 0},
        {{3, 2}, 0},
        {{0, 3}, 1},
        {{1, 3}, 1},
        {{2, 3}, 0},
        {{3, 3}, 0},
    };
    
    map<ll, ll> xr = {{0, 3}, {3, 0}, {1, 2}, {2, 1}};
    map<ll, ll> yr = {{0, 1}, {1, 0}, {2, 3}, {3, 2}};
    
    ll ans = m[{x, y}];
    if (abs(x - y) <= 1) ans = 0;
    
    while (!reflect.empty()) {
        if (reflect.back() == 1) ans = yr[ans];
        else ans = xr[ans];
        reflect.pop_back();
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