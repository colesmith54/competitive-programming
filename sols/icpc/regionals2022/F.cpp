#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    map<string, int> f;
    
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int x; cin >> x;
        
        f[s] += x;
    }
    
    vector<pair<string, int>> v(f.begin(), f.end());
    sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
    
    cout << f.size() << '\n';
    for (auto& [k, d] : v) {
        cout << k << ' ' << d << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}