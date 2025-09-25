// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;

class DSU {
    vi p;
    vi rank;
public:
    DSU(int n) {
        p.assign(n, 0);
        for (int i = 0; i < n; i++) p[i] = i;
        rank.assign(n, 1);
    }

    int find(int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        int x = find(u), y = find(v);
        if (x == y) return false;

        if (rank[x] > rank[y]) swap(x, y);
        else if (rank[x] == rank[y]) rank[y]++;

        p[x] = y;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sz = n * (n - 1) / 2;
    vvi edges(sz, vi(3, 0));

    int dist, idx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist;
            if (i < j) edges[idx++] = {i, j, dist};
        }
    }

    sort(edges.begin(), edges.end(), [](const vi& a, const vi& b) {
        return a[2] < b[2];
    });

    DSU d = DSU(n);
    int u, v;
    for (const vi& edge : edges) {
        u = edge[0], v = edge[1];
        if (d.unite(u-1, v-1)) {
            cout << u << ' ' << v << '\n';
        }
    }
}