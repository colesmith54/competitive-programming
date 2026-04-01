#include <bits/stdc++.h>

using namespace std;

class DSU {
    vector<int> p, r;
public:
    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        r.assign(n, 0);
    }
    
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
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
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    
    DSU d(n);
    vector<int> memo(n, -1);
    vector<int> f(n + 1, 0);

    
    for (int i = 0; i < n - k; ++i) {
        if (a[i] != a[i + k]) {
            if (b[i] != -1 && b[i] != a[i]) goto nah;
            if (b[i + k] != -1 && b[i + k] != a[i + k]) goto nah;
            
            b[i] = a[i];
            b[i + k] = a[i + k];
        }
    }
    
    for (int i = 0; i < n - k; ++i) {
        if (a[i] == a[i + k]) {
            d.unite(i, i + k);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (b[i] != -1) {
            int rep = d.find(i);
            if (memo[rep] != -1 && memo[rep] != b[i]) goto nah;
            memo[rep] = b[i];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        int rep = d.find(i);
        if (memo[rep] != -1) {
            b[i] = memo[rep];
        }
    }
    
    for (int i = 0; i < k; ++i) ++f[a[i]];
    for (int i = 0; i < k; ++i) {
        if (b[i] != -1 && !f[b[i]]--) goto nah;
    }
    
    cout << "YES\n";
    return;
    
nah:
    
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}