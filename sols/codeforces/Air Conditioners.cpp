#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(k);
    for (auto& x : a) cin >> x;
    
    vector<ll> t(k);
    for (auto& x : t) cin >> x;
    
    vector<ll> ans(n + 1, 2e9);
    for (int i = 0; i < k; ++i) {
        ans[a[i]] = min(ans[a[i]], t[i]);
    }
    
    ll curr = 2e9;
    for (int i = 1; i <= n; ++i) {
        curr = min(++curr, ans[i]);
        ans[i] = min(ans[i], curr);
    }
    
    curr = 2e9;
    for (int i = n; i > 0; --i) {
        curr = min(++curr, ans[i]);
        ans[i] = min(ans[i], curr);
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) solve();
}