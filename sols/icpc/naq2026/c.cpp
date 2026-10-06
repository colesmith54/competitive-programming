#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll mod = 998244353;
    
    vector<ll> fact(1e5 + 1, 0);
    fact[0] = 1;
    for (int i = 1; i <= 1e5; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
    
        vector<pair<int, int>> blocks(n);
        for (auto& [x, y] : blocks) {
            cin >> x >> y;
            if (x < y) swap(x, y);
        }
        
        sort(blocks.begin(), blocks.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second > b.second;
        });
    
        map<pair<int, int>, int> cnt;
        vector<pair<int, int>> groups;
    
        for (auto& b : blocks) {
            if (groups.empty() || groups.back() != b) {
                groups.push_back(b);
            }
            ++cnt[b];
        }
    
        ll ans = 1;
        if (groups[0].first != groups[0].second) ++ans;
        
        for (auto& [_, v] : cnt) {
            ans = (ans * fact[v]) % mod;
        }
    
        int sz = groups.size();
        for (int i = 0; i < sz - 1; ++i) {
            ll w = groups[i].first - groups[i + 1].first + 1;
            ll l = groups[i].second - groups[i + 1].second + 1;
            
            ll ways = 0;
            if (w > 0 && l > 0) ways = (w * l) % mod;
            
            if (groups[i + 1].first != groups[i + 1].second) {
                w = groups[i].first - groups[i + 1].second + 1;
                l = groups[i].second - groups[i + 1].first + 1;
                if (w > 0 && l > 0) ways = (ways + (w * l) % mod) % mod;
            }
            
            ans = (ans * ways) % mod;
        }
        
        cout << ans << '\n';
    }
}