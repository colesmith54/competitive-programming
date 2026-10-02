#include <bits/stdc++.h>

using namespace std;

void solve() {
    string t, p;
    cin >> t >> p;

    int n = t.size();

    vector<int> a(n);
    vector<int> rem(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        rem[--a[i]] = i + 1;
    }

    auto possible = [&](int k) {
        int j = 0;

        for (int i = 0; i < n && j < p.size(); ++i) {
            if (rem[i] > k && t[i] == p[j]) {
                ++j;
            }
        }

        return j == p.size();
    };

    int l = 0;
    int r = n - p.size();
    int ans = 0;

    while (l <= r) {
        int m = l + (r - l) / 2;

        if (possible(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}