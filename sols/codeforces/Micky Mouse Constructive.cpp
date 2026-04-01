#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    
    int ans = 0;
    int d = abs(x - y);
    
    for (int i = 1; i * i <= d; ++i) {
        if (d % i == 0) {
            ++ans;
            if (i * i != d) ++ans;
        }
    }
    
    cout << max(ans, 1) << '\n';
    for (int i = 0; i < x; ++i) cout << "1 ";
    for (int i = 0; i < y; ++i) cout << "-1 ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}