#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int z = count(s.begin(), s.end(), '0');
    int o = n - z;
    
    // odd zeros -> do all zeros
    // even zeros and even ones -> do all ones 
    
    if (z % 2 == 1) {
        cout << z << '\n';
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                cout << (i + 1) << ' ';
            }
        }
        cout << '\n';
    } else if (o % 2 == 0) {
        cout << o << '\n';
        if (o) {
            for (int i = 0; i < n; ++i) {
                if (s[i] == '1') {
                    cout << (i + 1) << ' ';
                }
            }
            cout << '\n';
        }
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}