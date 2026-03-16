#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<string> s(n);
    for (auto& x : s) cin >> x;
    
    set<string> seen(s.begin(), s.end());
    
    for (int i = 0; i < n; ++i) {
        const string& curr = s[i];
        bool found = false;
        
        for (int j = 1; j < curr.size(); ++j) {
            string u = curr.substr(0, j);
            string v = curr.substr(j);
            
            if (seen.contains(u) && seen.contains(v)) {
                found = true;
                break;
            }
        }
        
        cout << (found ? '1' : '0');
    }
    
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}