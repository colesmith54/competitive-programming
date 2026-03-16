#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    
    int nx = (y >= 0) ? 2 * y : -4 * y;
    // I am now at (nx, y)
    // I need to go from nx -> x
    
    if (nx == x) {
        cout << "YES\n";
        return;
    } else if (nx > x) {
        cout << "NO\n";
        return;
    }
    
    int needed = x - nx;
    // can take steps of 6, and then 3
    // so needed = 0 (mod 3)?
    
    cout << (needed % 3 ? "NO\n" : "YES\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}