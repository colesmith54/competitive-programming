#include <bits/stdc++.h>

using namespace std;

class DSU {
    vector<int> p, r;
public:
    DSU(int n) {
        p.assign(n, 0);
        iota(p.begin(), p.end(), 0);
        r.assign(n, 1);
    }

    int find(int x) {
        if (p[x] == x)
            return x;
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

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    
    int cc = n + m;
    DSU d(cc + 2);
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        cc -= d.unite(r, c + n);
    }
    
    cout << --cc;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}