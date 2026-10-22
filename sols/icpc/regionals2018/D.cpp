#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Gig {
    int v, s, e, m;
    
    bool operator<(const Gig& other) const {
        return e < other.e;
    }
};

void solve() {
    int g, n, r;
    cin >> g >> n >> r;
    
    vector<vector<int>> d(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 1; i <= n; ++i) d[i][i] = 0;
    
    while (r--) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }
    
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    
    vector<Gig> gigs(g);
    for (auto& gig : gigs) cin >> gig.v >> gig.s >> gig.e >> gig.m;
    sort(gigs.begin(), gigs.end());

    vector<map<int, ll>> venues(n + 1);
    venues[1][0] = 0;

    ll ans = 0;
    
    for (auto& gig : gigs) {
        ll best = -1;
        
        for (int v = 1; v <= n; ++v) {
            auto& ven = venues[v];
            int t = gig.s - d[v][gig.v];
            
            auto it = ven.upper_bound(t);
            if (it == ven.begin()) continue;
            --it;
            
            best = max(best, it->second + gig.m);
        }
        
        if (best == -1) continue;
        auto& ven = venues[gig.v];
        
        if (!ven.empty()) {
            best = max(best, ven.rbegin()->second);
        }
        
        ven[gig.e] = best;
        ans = max(ans, best);
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}