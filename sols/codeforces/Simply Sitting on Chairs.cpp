#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> p[i];
    
    vector<int> bad(n + 1, 0);
    for (int i = 1; i <= n; ++i) if (p[i] > i) ++bad[p[i]];
    
    int ans = 1;
    int pre = 0;
    
    for (int i = 1; i <= n; ++i) {
        pre += bad[i];
        ans = max(ans, i - pre);
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