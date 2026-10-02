#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int ans = 0;
    vector<int> a(n);
    
    for (auto& x : a) {
        cin >> x;
        if (x > 1) ans += x;
    }
    
    if (a.back() == 1) ++ans;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}