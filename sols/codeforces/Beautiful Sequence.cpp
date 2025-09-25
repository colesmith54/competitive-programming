#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 998244353;
const ll N = 2e5 + 5;

vector<ll> p(N, 1), pi(N, 1);

ll modexp(ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    ll ans = 0;
    ll w_ones = 0;
    ll ones = 0;
    ll twos = 0;

    for (int x : a) {
        if (x == 1) {
            w_ones = (w_ones + pi[twos]) % MOD;
            ++ones;
        } else if (x == 2) {
            ++twos;
        } else {
            ll add = ((p[twos] * w_ones) % MOD - ones) % MOD;
            if (add < 0) add += MOD;
            ans = (ans + add) % MOD;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < N; ++i) {
        p[i] = (p[i - 1] << 1) % MOD;
    }

    ll inv = modexp(2, MOD - 2);
    for (int i = 1; i < N; ++i) {
        pi[i] = (inv * pi[i - 1]) % MOD;
    }

    int t;
    cin >> t;
    while (t--) solve();
}