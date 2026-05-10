#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    // letters in col i
    // 1 -> we have letter b
    // 0 -> if not
    // 26 -> 31
    vector<int> mask(n, 0);
    
    while (k--) {
        string s;
        cin >> s;
        
        for (int i = 0; i < n; ++i) {
            mask[i] |= (1 << (s[i] - 'a'));
        }
    }
    
    vector<int> d;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            d.push_back(i);
            d.push_back(n / i);
        }
    }
    
    sort(d.begin(), d.end());
    
    for (int x : d) {
        string s;
        bool good = true;
        
        for (int i = 0; i < x; ++i) {
            // 111111... for every letter
            // 100000... -> 01111111
            int curr = (1 << 26) - 1;
            
            for (int j = i; j < n; j += x) {
                curr &= mask[j];
            }
            
            if (!curr) {
                good = false;
                break;
            }
            
            s.push_back((char) ('a' + __builtin_ctz(curr)));
        }
        
        if (!good) {
            continue;
        }
        
        string ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(s[i % x]);
        }
        
        cout << ans << '\n';
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}