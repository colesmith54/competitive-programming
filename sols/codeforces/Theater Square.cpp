#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    int ones = 0;
    int l = y1 - 1;
    int r = m - y2;
    
    for (int i = 1; i <= n; ++i) {
        if (x1 <= i && i <= x2) {
            ones += l % 2 + r % 2;
        } else {
            ones += m % 2;
        }
    }
    
    cout << (ones + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}