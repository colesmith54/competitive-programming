#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<ll> a(3);
    for (auto& x : a)
        cin >> x;

    vector<ll> p(3);
    for (auto& x : p)
        cin >> x;

    ll d;
    cin >> d;

    vector<ll> q(3, 0);

    for (char c : s) {
        if (c == 'B') ++q[0];
        else if (c == 'S') ++q[1];
        else ++q[2];
    }

    auto possible = [&](ll k) {
        __int128 c = 0;
        for (int i = 0; i < 3; ++i)
            c += (p[i] * max(0LL, (q[i] * k) - a[i]));
        return c <= d;
    };

    ll l = 0;
    ll r = 1e15;
    ll ans = l;

    while (l <= r) {
        ll m = l + (r - l) / 2;
        if (possible(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << ans;
}