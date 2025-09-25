#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, p;
    cin >> n >> k >> p;

    if (k == 0) {
        cout << 0 << '\n';
        return;
    }
    
    if (abs(k) > n * p) {
        cout << -1 << '\n';
        return;
    }

    k = abs(k);
    cout << (k + p - 1) / p << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}