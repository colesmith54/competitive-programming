#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    const int maxc = n * m + 1;
    set<int> colors;
    vector<bool> adj(maxc, false);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int color = a[i][j];
            colors.insert(color);
            if (j + 1 < m && a[i][j + 1] == color) adj[color] = true;
            if (i + 1 < n && a[i + 1][j] == color) adj[color] = true;
        }
    }

    int total_steps = 0;
    int max_steps = 0;
    for (int c : colors) {
        int steps = adj[c] ? 2 : 1;
        total_steps += steps;
        max_steps = max(max_steps, steps);
    }

    cout << total_steps - max_steps << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}