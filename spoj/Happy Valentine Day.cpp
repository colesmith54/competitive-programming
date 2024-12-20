// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

struct State {
    int r, c, mask, steps;
    State(int r, int c, int mask, int steps) : r(r), c(c), mask(mask), steps(steps) {};
};

void solve() {
    int m, n;
    cin >> m >> n;

    vector<string> grid(m);
    for (auto& r : grid) cin >> r;

    int sr = -1, sc = -1, er = -1, ec = -1;
    vii chocs;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'T') {
                sr = i;
                sc = j;
            } else if (grid[i][j] == 'W') {
                er = i;
                ec = j;
            } else if (grid[i][j] == 'C') {
                chocs.emplace_back(i, j);
            }
        }
    }

    int c = chocs.size();
    int tmask = (1 << c) - 1;

    unordered_map<ll, int> choc_idx;
    for (int i = 0; i < c; i++) {
        ll key = (ll) chocs[i].first * n + chocs[i].second;
        choc_idx[key] = i;
    }

    const vii dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bitset<1024>>> visited(m, vector<bitset<1024>>(n, bitset<1024>()));

    queue<State> q;
    q.emplace(sr, sc, 0, 0);
    visited[sr][sc].set(0);

    while (!q.empty()) {
        auto curr = q.front(); q.pop();

        if (curr.r == er && curr.c == ec && curr.mask == tmask) {
            cout << curr.steps << '\n';
            return;
        }

        for (auto& [dr, dc] : dirs) {
            int nr = curr.r + dr, nc = curr.c + dc;
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if (grid[nr][nc] == '#') continue;

            int nmask = curr.mask;
            if (grid[nr][nc] == 'C') {
                ll key = (ll) nr * n + nc;
                nmask |= (1 << choc_idx[key]);
            }

            if (!visited[nr][nc].test(nmask)) {
                visited[nr][nc].set(nmask);
                q.emplace(nr, nc, nmask, curr.steps + 1);
            }
        }
    }

    cout << "Mission Failed!\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}