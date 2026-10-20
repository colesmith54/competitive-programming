#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> m(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        m[i] = x;
    }
    
    while (q--) {
        int t;
        cin >> t;
        
        if (t == 1) {
            int c, x;
            cin >> c >> x;
            m[c] = x;
        } else {
            int a, b;
            cin >> a >> b;
            cout << abs(m[a] - m[b]) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}