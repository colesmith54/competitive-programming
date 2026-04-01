#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class DSU {
    vector<int> p, r;
public:    
    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        r.assign(n, 0);
    }
    
    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        
        if (r[x] > r[y]) swap(x, y);
        else if (r[x] == r[y]) ++r[y];
        
        p[x] = y;
        return true;
    }
};

struct Edge {
    int u, v, w;
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    int diff = 1e9;
    vector<Edge> e(m);
    for (auto& x : e) {
        cin >> x.u >> x.v >> x.w; --x.u; --x.v;
        diff = min(diff, abs(x.w - k));
    }
    
    sort(e.begin(), e.end(), [k](Edge a, Edge b) {
        return a.w < b.w;
    });
    
    DSU d(n);
    bool above = false;
    ll cnt = 0;
    
    for (auto& [u, v, w] : e) {
        if (d.unite(u, v)) {
            if (w > k) above = true;
            cnt += max(0, w - k);
        }
    }
    
    cout << (above ? cnt : diff) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}