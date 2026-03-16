#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> h(n);
    for (auto& x : h) cin >> x;
    
    for (int i = 0; i < n - 1; ++i) {
        int target = max(0, h[i + 1] - k);
        m += h[i] - target;
        
        if (m < 0) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}