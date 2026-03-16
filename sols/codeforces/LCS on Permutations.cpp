#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    
    vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        pos[a[i]] = i;
    }
    
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = pos[b[i]];
    }
    
    vector<int> dp;
    for (int x : c) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        
        if (it == dp.end()) {
            dp.push_back(x);
        } else {
            *it = x;
        }
    }
    
    cout << dp.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
