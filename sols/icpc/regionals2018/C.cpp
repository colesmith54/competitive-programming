#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    
    int n = s.size();
    for (int sz = n; sz > 0; --sz) {
        set<vector<int>> sub;
        vector<int> v(26, 0);
        
        int l = 0, r = 0;
        while (r < sz) ++v[t[r++] - 'a'];
        while (r < n) {
            sub.insert(v);
            --v[t[l++] - 'a'];
            ++v[t[r++] - 'a'];
        }
        
        l = 0; r = 0;
        sub.insert(v);
        v.assign(26, 0);
        while (r < sz) ++v[s[r++] - 'a'];
        while (r < n) {
            if (sub.contains(v)) {
                cout << s.substr(l, sz) << '\n';
                return;
            }
            --v[s[l++] - 'a'];
            ++v[s[r++] - 'a'];
        }
        
        if (sub.contains(v)) {
            cout << s.substr(l, sz) << '\n';
            return;
        }
    }
    
    cout << "NONE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}