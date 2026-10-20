#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    int ma = *max_element(a.begin(), a.end());
    int mi = *min_element(a.begin(), a.end());
    
    int ans = ma | mi;
    int diff = mi ^ ma;
    
    for (int i = 31; i >= 0; --i) {
        if ((diff >> i) & 1) {
            ans |= 2 * (1 << i) - 1;
        }
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