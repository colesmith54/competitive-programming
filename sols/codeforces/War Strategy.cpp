#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    int l = 0;
    int r = 0;
    
    k = max(k, n - k + 1);
    
    while (true) {
        if (l < n - k && l + r + max(l + 1, r) <= m) ++l;
        if (r < k - 1 && l + r + max(l, r + 1) <= m) ++r;
        else break;
    }
    
    cout << l + r + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}