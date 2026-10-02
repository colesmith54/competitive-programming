#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> a(n);
    for (auto& x : a) cin >> x.first;
    for (auto& x : a) cin >> x.second;
    
    sort(a.begin(), a.end(), [](auto& x, auto& y) {
        return (x.first - x.second) < (y.first - y.second);
    });
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i < k || a[i].first < a[i].second) {
            ans += a[i].first;
        } else {
            ans += a[i].second;
        }
    }
    
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}