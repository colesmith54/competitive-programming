#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    int ans = 0;
    stack<int> stk;
    
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && stk.top() != a[i] - 1) {
            stk.pop();
        }
        
        if (stk.empty()) {
            ++ans;
        }
        
        stk.push(a[i]);
    }
    
    // 2 3 4 5 4 3 4 4 5 6 -> 1
    // 5 4 3 -> 3
    
    // dsu but no path compression or union by rank?
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}