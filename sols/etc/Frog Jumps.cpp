#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a;
    cin >> a;

    int n = a.size();

    auto possible = [&](int k) {
        int b = k - 1;
        for (int i = 0; i < n; ++i) {
            if (i > b) return false;
            if (a[i] == 'R') b = max(b, i + k);
        }
        return b >= n;
    };

    int l = 1;
    int r = 3e5;
    int ans = r;

    while (l <= r) {
        int m = (l + r) / 2;
        if (possible(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
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