#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int ans = 1e9;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    sort(a.begin(), a.end());
    auto it = unique(a.begin(), a.end());
    int distinct = distance(a.begin(), it);

    for (int x : a) {
        if (x >= distinct) {
            ans = min(ans, x);
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