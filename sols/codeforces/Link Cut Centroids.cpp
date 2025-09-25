// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> Centroid(const vector<vector<int>>& g, vector<int>& p) {
    int n = g.size();
    vector<int> centroid;
    vector<int> sz(n);
    function<void(int, int)> dfs = [&](int u, int prev) {
        sz[u] = 1;
        bool is_centroid = true;
        for (auto& v : g[u]) {
            if (v == prev) continue;
            dfs(v, u);
            sz[u] += sz[v];
            p[v] = u;
            if (2*sz[v] > n) is_centroid = false;
        }
        if (n-sz[u] > n/2) is_centroid = false;
        if (is_centroid) centroid.push_back(u);
    };
    dfs(0, -1);
    return centroid;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n);

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> p(n, -1);
    vector<int> centroids = Centroid(g, p);

    if (centroids.size() == 1) {
        // cut any edge and add it back
        cout << 1 << ' ' << g[0].back() + 1 << '\n';
        cout << 1 << ' ' << g[0].back() + 1 << '\n';
    } else {
        int x = centroids[0];
        int y = centroids[1];

        // ensure x is y's parent
        if (y == p[x]) swap(x, y);

        // cut a random leaf in y's subtree
        int u = y;
        vector<bool> vis(n, false);
        vis[u] = true;

        while (1) {
            bool leaf = true;
            for (auto& v : g[u]) {
                if (vis[v] || v == x) continue;
                u = v;
                vis[v] = true;
                leaf = false; break;
            }
            if (leaf) break;
        }

        cout << u + 1 << ' ' << p[u] + 1 << '\n';

        // link it with x
        cout << u + 1 << ' ' << x + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}