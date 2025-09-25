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

    bool sameSet(int u, int v) {
        return find(u) == find(v);
    }

    bool unite (int u, int v) {
        if (sameSet(u, v)) return false;
        int x = find(u), y = find(v);

        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;

        if (rank[x] == rank[y]) rank[y]++;
        return true;
    }
};

void solve() {
    int m, c;
    cin >> m >> c;

    int sz = c * (c - 1) / 2;
    vvi edges(sz, vi(3, 0));

    for (int i = 0; i < sz; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    sort(edges.begin(), edges.end(), [](const vi& a, const vi& b) {
        return a[2] < b[2];
    });

    DSU d = DSU(c);
    int u, v, w, milk = 0;

    for (const vi& edge : edges) {
        u = edge[0], v = edge[1], w = edge[2];
        if (d.unite(u, v)) milk += w;
    }

    if (milk + c <= m) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}