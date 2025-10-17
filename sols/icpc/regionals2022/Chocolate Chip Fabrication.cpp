#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (auto& r : grid) {
        for (auto& c : r) {
            cin >> c;
        }
    }

    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != 'X') continue;
            if (i == 0 || j == 0 || i == n-1 || j == m-1 || grid[i-1][j] == '-' || grid[i][j+1] == '-' || grid[i][j-1] == '-' || grid[i+1][j] == '-') {
                q.emplace(i, j);
                grid[i][j] = '+';
            }
        }
    }

    if (q.empty()) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    constexpr int dir[5] = {-1, 0, 1, 0, -1};

    while (!q.empty()) {
        ++ans;
        int sz = q.size();
        while (sz--) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int nr = r + dir[k];
                int nc = c + dir[k + 1];

                if (nr < 0 || nc < 0 || nr == n || nc == m || grid[nr][nc] != 'X') {
                    continue;
                }

                q.emplace(nr, nc);
                grid[nr][nc] = '+';
            }
        }
    }

    cout << ans;
}