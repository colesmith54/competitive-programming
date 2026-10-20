#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    if (n == 1) {
        cout << "0\n";
        return;
    }
    
    if (n == 2) {
        cout << "1\n1 1\n";
        return;
    }
    
    n--;
    cout << (n / 2) + 1 << '\n';
    cout << "1 2\n";
    
    for (int i = 2; i <= n; i += 2) {
        cout << i << ' ' << min(i + 2, n) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}