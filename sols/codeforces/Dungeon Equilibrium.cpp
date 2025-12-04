#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> f(n + 1, 0);
    for (auto& x : a) {
        cin >> x;
        ++f[x];
    }

    // if f[x] < x, delete all
    // if f[x] >= x, delete f[x] - x;

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += (f[i] < i) ? f[i] : f[i] - i;
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