#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 2; i <= n; ++i) cin >> p[i];

    vector<int> a(n + 1);
    for (int i = 2; i <= n; ++i) cin >> a[i];

    vector<int> h(n + 1, 0);
    vector<int> r(n + 1, 0);
    vector<bool> l(n + 1, true);

    for (int i = 2; i <= n; ++i) {
        l[p[i]] = false;
        h[i] = h[p[i]] + (a[i] == 1 ? 1 : 0);
        r[i] = r[p[i]] + (a[i] == 2 ? 1 : 0);
    }

    int best = -1;
    int min_h = 2e9, min_r = 2e9;

    for (int i = 1; i <= n; ++i) {
        if (l[i]) {
            if (h[i] < min_h || (h[i] == min_h && r[i] < min_r)) {
                min_h = h[i];
                min_r = r[i];
                best = i;
            }
        }
    }

    cout << best << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) solve();
}