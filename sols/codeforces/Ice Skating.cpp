#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> snow;
    vector<char> vis(n, false);
    
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        snow.emplace_back(x, y);
    }

    function<void(int, int)> dfs = [&](int sx, int sy) {
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                auto [cx, cy] = snow[i];
                if (cx == sx || cy == sy) {
                    vis[i] = true;
                    dfs(cx, cy);
                }
            }
        }
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            ++ans;
            vis[i] = true;
            dfs(snow[i].first, snow[i].second);
        }
    }

    cout << ans - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}