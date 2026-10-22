#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct System {
    int g;
    bool h;
};

void solve() {
    int n;
    cin >> n;
    
    vector<System> g(n + 1);
    multiset<int> human;
    multiset<int> alien;
    
    for (int i = 1; i <= n; ++i) {
        cin >> g[i].g;
        char h; cin >> h;
        g[i].h = h == 'h';
        
        if (g[i].h) human.insert(g[i].g);
        else alien.insert(g[i].g);
    }
    
    vector<vector<int>> a(n + 1);
    int e; cin >> e;
    
    while (e--) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    
    ll ans = 9e18;
    
    auto check = [&](int i) {
        __int128 u = g[i].g;
        auto& m = g[i].h ? alien : human;
        auto r = m.lower_bound(g[i].g);

        if (r != m.end()) {
            __int128 v = *r;
            __int128 d = v * v * v - u * u * u;
            if (d < 0) d = -d;
            if (d < ans) ans = d;
        }
        
        if (r != m.begin()) {
            __int128 v = *(--r);
            __int128 d = v * v * v - u * u * u;
            if (d < 0) d = -d;
            if (d < ans) ans = d;
        }
    };
    
    auto update = [&](int i, int d) {
        auto& m = g[i].h ? human : alien;
        auto it = m.find(g[i].g);
        m.erase(it);

        g[i].g += d;
        m.insert(g[i].g);
    };
    
    for (int i = 1; i <= n; ++i) {
        check(i);
        
        update(i, -1);
        for (int v : a[i]) update(v, 1);
        
        check(i);
        for (int v : a[i]) check(v);
        
        update(i, 1);
        for (int v : a[i]) update(v, -1);
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}