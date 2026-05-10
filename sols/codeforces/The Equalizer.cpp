#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    int a = 0;
    int b = n * k;
    
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a += x;
    }
    
    if (a & 1 || ~b & 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}