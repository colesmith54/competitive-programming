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
    DSU (int n) {
        p.resize(n);
        for (int i = 0; i < n; i++) p[i] = i;
        rank.assign(n, 1);
    }
    int find(int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
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

void solve(int n, int m) {
    vvi edges(m, vi(3, 0));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    sort(edges.begin(), edges.end(), [](const vi& a, const vi& b) {
        return a[2] < b[2];
    });

    DSU d = DSU(n);

    vii out;
    int u, v, w, total = 0;

    for (const vi& edge : edges) {
        u = edge[0], v = edge[1], w = edge[2];
        if (d.unite(u, v)) {
            total += w;
            if (u > v) swap(u, v);
            out.emplace_back(u, v);
        }
    }

    unordered_set<int> parents;
    for (int i = 0; i < n; i++) {
        parents.insert(d.find(i));
    }

    if (parents.size() > 1) {
        cout << "Impossible\n";
        return;
    }

    sort(out.begin(), out.end());

    cout << total << '\n';
    for (const auto& [p, q] : out) {
        cout << p << ' ' << q << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        solve(n, m);
    }
}