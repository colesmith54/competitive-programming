#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, x, k;
    cin >> n >> x >> k;
    
    string s;
    cin >> s;

    vector<ll> p(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + (s[i - 1] == 'L' ? -1 : 1);
    }

    auto reset = [&](ll st) {
        for (ll i = 1; i <= n; ++i) if (st + p[i] == 0) return i;
        return -1LL;
    };

    ll ans = 0;
    ll a = reset(x);

    if (a == -1 || a > k) {
        cout << ans << '\n';
        return;
    }

    ++ans;
    ll cycle = reset(0);

    if (cycle == -1) {
        cout << ans << '\n';
        return;
    }

    ll rem = k - a;
    ans += rem / cycle;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}