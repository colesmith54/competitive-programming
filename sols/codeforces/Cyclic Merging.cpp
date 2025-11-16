#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    ll sum = 0;
    int worst = 0;

    for (int i = 0; i < n; ++i) {
        int edge = max(a[i], a[(i + 1) % n]);
        sum += edge;
        worst = max(worst, edge);
    }

    cout << sum - worst << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}