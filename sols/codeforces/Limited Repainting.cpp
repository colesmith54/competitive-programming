#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;

    int ma = 0;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
        ma = max(ma, x);
    }

    auto possible = [&](int p) {
        int seg = 0;
        int i = 0;
        while (i < n) {
            if (s[i] == 'R' && a[i] > p) { ++i; continue; }
            bool need = false;
            while (i < n && (s[i] == 'B' || a[i] <= p)) {
                if (s[i] == 'B' && a[i] > p) need = true;
                ++i;
            }
            if (need) ++seg;
        }

        return seg <= k;
    };

    int ans = 0;
    int l = 0;
    int r = ma;

    while (l <= r) {
        int m = l + (r - l) / 2;
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