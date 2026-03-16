#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int m = 0;
    int ans = 0;
    for (auto x : a) {
        ans += m > x;
        m = max(m, x);
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
