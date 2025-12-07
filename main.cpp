#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> ps(n);
    for (auto& [x, y] : ps) {
        cin >> x >> y;
    }

    sort(ps.begin(), ps.end(), [](const pair<int, int>& p, const pair<int, int>& q) {
        return min(p.first, p.second) < min(q.first, q.second);
    });

    auto possible = [&](int m) -> bool {
        int min_x = -1e9;
        int min_y = -1e9;

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                auto p = ps[i];
                auto q = ps[j];

                if (q.second <= p.second + 2*m && q.first <= p.first + 2*m) {
                    continue;
                }
                if (q.second >= p.second - 2*m && q.first >= p.first - 2*m) {
                    continue;
                }

                return false;
            }
        }

        return true;
    };

    int l = 0;
    int r = 1e9;
    int ans = r;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (possible(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << 2 * ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}