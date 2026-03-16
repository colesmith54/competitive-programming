#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<pair<double, double>> a(n);
    for (auto& x : a) cin >> x.first >> x.second;
    
    double ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans = max(ans, ans * (1.0 - (a[i].second / 100.0)) + a[i].first);
    }
    
    cout << fixed << setprecision(15) << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}