#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    vector<int> diff(n + 1, 0);
    
    int l, r;
    while (q--) {
        cin >> l >> r;
        
        ++diff[l - 1];
        --diff[r];
    }
    
    for (int i = 0; i < n; ++i) {
        diff[i + 1] += diff[i];
    }
    
    sort(diff.rbegin(), diff.rend());
    sort(a.rbegin(), a.rend());
    
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (ll)a[i] * diff[i];
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}