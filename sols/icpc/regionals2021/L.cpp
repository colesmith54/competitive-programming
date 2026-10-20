#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string l, u;
    cin >> l >> u;
    
    const ll mod = 998244353;
    
    vector<ll> rainbow(1e5 + 1, 0);
    rainbow[0] = 1;
    for (int i = 1; i <= 1e5; ++i) {
        rainbow[i] = (9 * rainbow[i - 1]) % mod;
    }
    
    int d1 = l.size();
    int d2 = u.size();
    
    int ans = 0;
    for (int d = d1 + 1; d < d2; ++d) {
        ans = (ans + rainbow[d]) % mod;
    }
    
    auto cnt = [&rainbow](string& s) -> ll {
        int ret = 0;
        int prev = -1;
        int sz = s.size();
        
        for (int i = 0; i < sz; ++i) {
            int dig = s[i] - '0';
            int num = 0;
            
            for (int d = i == 0; d < dig; ++d) {
                num += d != prev;
            }
            
            ret = (ret + num * rainbow[sz - i - 1]) % mod;
            if (dig == prev) return ret;
            prev = dig;
        }
        
        return (ret + 1) % mod;
    };
    
    bool rainbow_l = true;
    for (int i = 1; i < d1; ++i) {
        if (l[i - 1] == l[i]) {
            rainbow_l = false;
            break;
        }
    }
    
    if (d1 == d2) {
        ans = (cnt(u) - cnt(l) + rainbow_l + mod) % mod;
    } else {
        ans = (ans + rainbow[d1] - cnt(l) + rainbow_l + mod) % mod;
        ans = (ans + cnt(u)) % mod;
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}