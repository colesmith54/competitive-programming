#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    vector<int> f(10, 0);
    for (char c : s) ++f[c - '0'];
    
    int tot = 0;
    for (int d = 0; d <= 9; ++d) {
        tot += d * f[d];
    }
    
    vector<int> sum(tot + 1, 0);
    for (int i = 0; i <= min(tot, 9); ++i) {
        sum[i] = i;
    }
    
    for (int i = 10; i <= tot; ++i) {
        sum[i] = sum[i / 10] + i % 10;
    }
    
    for (int i = 0; i <= tot; ++i) {
        string ans;
        int curr = i;
        
        while (curr > 9) {
            ans += to_string(curr);
            curr = sum[curr];
        }
        ans += to_string(curr);
        
        bool ok = true;
        for (char c : ans) {
            --f[c - '0'];
            if (f[c - '0'] < 0) {
                ok = false;
            }
        }
        
        if (ok) {
            int rest = 0;
            for (int d = 0; d <= 9; ++d) {
                rest += d * f[d];
            }
            
            if (rest == 0 || rest == i) {
                string res;
                for (int d = 9; d >= 0; --d) {
                    res += string(f[d], d + '0');
                }
                
                res += ans;
                cout << res << '\n';
                return;
            }
        }
        
        for (char c : ans) {
            ++f[c - '0'];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}