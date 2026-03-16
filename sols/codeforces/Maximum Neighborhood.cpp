#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int ans = 0;
    int start = max(1, n * n - 2 * (n + 1));
    for (int i = start; i <= n*n; ++i) {
        int curr = i;
        if (i % n != 0) curr += (i + 1);
        if (i % n != 1) curr += (i - 1);
        if (i > n) curr += (i - n);
        if (i < n * n - n + 1) curr += (i + n);
        ans = max(ans, curr);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}