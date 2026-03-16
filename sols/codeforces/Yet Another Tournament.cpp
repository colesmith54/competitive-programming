#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> b = a;
    sort(b.begin(), b.end());

    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + b[i]; 
    }
    
    int ans = n + 1;
    
    for (int k = 0; k <= n; k++) {
        if (pre[k] > m) {
            break;
        }

        ans = min(ans, n - k + 1);
        
        if (k > 0 && k < n) {
            ll cost_with_swap = pre[k] - b[k-1] + a[k];
            if (cost_with_swap <= m) {
                ans = min(ans, n - k);
            }
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}