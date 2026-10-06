#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q, g;
    cin >> n >> q >> g;
    
    unordered_map<int, int> f, p;
    
    while (q--) {
        char t;
        cin >> t;
        
        if (t == 'P') {
            int s, a;
            cin >> s >> a;
        
            while (a--) {
                int i;
                cin >> i;
            
                if (p[i]) {
                    --f[p[i]];
                }
                
                p[i] = s;
                ++f[s];
            }
        } else {
            int s;
            cin >> s;
            cout << f[s] << '\n';
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