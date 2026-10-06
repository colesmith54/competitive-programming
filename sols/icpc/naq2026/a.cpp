#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 998244353;

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    n %= mod;
    
    ll ans = n * (n + 1) % mod;
    ans = ans * (n + 2) % mod;
    ans = ans * modpow(6, mod - 2) % mod;
    
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}