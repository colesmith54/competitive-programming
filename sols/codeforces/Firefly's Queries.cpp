// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

void solve() {
    int n, q;
    cin >> n >> q;

    vi a(n);
    for (int& x : a) cin >> x;
    ll total = accumulate(a.begin(), a.end(), 0LL);

    vector<ll> da(2 * n);
    for (int i = 0; i < n; i++) {
        da[i] = a[i]; da[i + n] = a[i];
    }

    vector<ll> prefix(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; i++){
        prefix[i+1] = prefix[i] + da[i];
    }

    ll l, r;
    while (q--) {
        cin >> l >> r;
        ll blockL = (l - 1) / n + 1;
        ll posL = (l - 1) % n;
        ll blockR = (r - 1) / n + 1;
        ll posR = (r - 1) % n;

        ll blocksBetween = max(0LL, blockR - blockL - 1);
        ll ans = blocksBetween * total;

        if (blockL == blockR) {
            ll start = blockL - 1;
            ans += prefix[start + posR + 1] - prefix[start + posL];
        }
        else{
            ll start = blockL - 1;
            ans += prefix[start + n] - prefix[start + posL];

            ll end = blockR - 1;
            ans += prefix[end + posR + 1] - prefix[end];
        }

        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
