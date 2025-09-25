#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k;
    cin >> k;

    int needed = k;
    vector<int> pts;

    while (needed) {
        int r = 0;
        while (r * (r + 1) / 2 <= needed) ++r;

        int add = (r * (r - 1) / 2);
        pts.push_back(r);
        needed -= add;
    }

    cout << accumulate(pts.begin(), pts.end(), 0) << '\n';
    int c = 0;
    for (int i = 0; i < pts.size(); ++i) {
        for (int j = 0; j < pts[i]; ++j) {
            cout << i << ' ' << ++c << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}