#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (abs(a[i] - a[i + 1]) == gcd(a[i], a[i + 1])) {
            ++ans;
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