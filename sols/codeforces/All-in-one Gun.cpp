#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, h, k;
    cin >> n >> h >> k;
    
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    
    vector<ll> pre(a.begin(), a.end());
    vector<ll> suf(a.begin(), a.end());
    
    for (int i = 0; i < n - 1; ++i) {
        pre[i + 1] = min(pre[i], a[i + 1]);
    }
    
    for (int i = n - 1; i > 0; --i) {
        suf[i - 1] = max(suf[i], a[i - 1]);
    }
    
    ll total = accumulate(a.begin(), a.end(), 0LL);
    ll lh = h % total;
    
    if (lh == 0) {
        cout << (n + k) * (h / total) - k << '\n';
        return;
    }
    
    ll li = n - 1; 
    for (int i = 0; i < n - 1; ++i) {
        lh -= a[i];
        if (lh <= 0) {
            li = i;
            break;
        }
        if (lh + pre[i] - suf[i + 1] <= 0) {
            li = i;
            break;
        }
    }
    
    ll ans = (n + k) * (h / total) + li + 1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}