#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    int ans = 1;
    int m = a[0];
    
    for (int i = 1; i < n; ++i) {
        if (a[i] >= m) {
            ++ans;
            m = max(m, a[i]);
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