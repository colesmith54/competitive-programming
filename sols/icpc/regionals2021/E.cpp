#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> d(n);
    for (auto& x : d) cin >> x;
    
    int ans = 0;
    stack<int> stk;
    
    for (int r = 0; r < n; ++r) {
        while (!stk.empty() && d[stk.top()] < d[r]) {
            ++ans;
            stk.pop();
        }
        
        ans += !stk.empty();
        stk.push(r);
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}