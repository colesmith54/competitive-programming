#include <bits/stdc++.h>

using namespace std;

class DSU {
    vector<int> p, r;
public:
    DSU(int n) {
        p.assign(n, 0);
        r.assign(n, 0);
        iota(p.begin(), p.end(), 0);
    }
    
    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    
    bool unite(int x, int y) {
        int u = find(x);
        int v = find(y);
        
        if (u == v) return false;
        
        if (r[u] > r[v]) swap(u, v);
        else if (r[u] == r[v]) ++r[v];
        
        p[u] = v;
        return true;
    }
};

struct Edge {
    int u, v;
    long double w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> a(n);
    for (auto& c : a) {
        int x, y, r;
        cin >> x >> y >> r;
        c = {x, y, r};
    }
    
    vector<Edge> e;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long dx = a[i][0] - a[j][0];
            long long dy = a[i][1] - a[j][1];
            long double d = sqrtl(dx * dx + dy * dy) - a[i][2] - a[j][2];
            e.push_back({i, j, d});
        }
    }
    
    sort(e.begin(), e.end());
    DSU d(n + 1);
    
    long double ans = 0;
    for (const Edge& ed : e) {
        if (d.unite(ed.u, ed.v)) {
            ans += ed.w;
        }
    }
    
    cout << fixed << setprecision(15) << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}