// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 998244353;
ll min_len, ans;
vector<ll> primes;

void dfs(ll L, ll R) {
    if (R - L < min_len) {
        min_len = R - L;
        ans = 1;
    } else if (R - L == min_len) {
        ans = (ans + 1) % MOD;
    }

    auto it = upper_bound(primes.begin(), primes.end(), (L + R) / 2.0);
    ll posLTR = distance(primes.begin(), it) - 1;
    if (posLTR >= 0 && primes[posLTR] > L) {
        dfs(primes[posLTR], R);
    }

    auto it2 = lower_bound(primes.begin(), primes.end(), (L + R) / 2.0);
    ll posRTL = distance(primes.begin(), it2);
    if (posRTL < primes.size() && primes[posRTL] < R) {
        dfs(L, primes[posRTL]);
    }
}

void segmented_sieve(ll L, ll R) {
    primes.clear();

    ll lim = sqrt(R) + 1;
    vector<bool> mark(lim + 1, false);
    vector<ll> pr;
    for (ll i = 2; i <= lim; ++i) {
        if (mark[i]) continue;
        pr.emplace_back(i);
        for (ll j = i * i; j <= lim; j += i) mark[j] = true;
    }

    vector<bool> isPrime(R - L + 1, true);
    for (ll p : pr) {
        ll start = max(p * p, ((L + p - 1) / p) * p);
        for (ll j = start; j <= R; j += p)
            isPrime[j - L] = false;
    }
    if (L == 1) isPrime[0] = false;

    for (ll i = 0; i < isPrime.size(); i++) {
        if (isPrime[i]) primes.emplace_back(L + i);
    }
}

void solve() {
    ll l, r;
    cin >> l >> r;

    // handle halves
    l *= 2;
    r *= 2;

    segmented_sieve(l, r);
    if (primes.empty()) {
        cout << 1 << '\n';
        return;
    }

    min_len = r - l;
    ans = 0;

    dfs(l, r);
    cout << (ans % MOD) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
