#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> g;
    vector<pair<int, int>> a(n + 1, {0, 0});

    int read = 0;
    int pos = 0;

    while (q--) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            ++a[x].first;
            g.emplace_back(x, a[x].first);
        } else if (t == 2) {
            read += a[x].first - a[x].second;
            a[x].second = a[x].first;
        } else {
            while (pos < x) {
                auto [app, idx] = g[pos++];
                if (idx > a[app].second) {
                    a[app].second = idx;
                    ++read;
                }
            }
        }

        cout << g.size() - read << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}