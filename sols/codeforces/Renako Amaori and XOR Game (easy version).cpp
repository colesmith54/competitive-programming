#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    int p = 0, q = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) continue;
        p ^= a[i];
        q ^= b[i];
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) continue;
        if (i % 2 == 0) {
            if (p ^ b[i]) {
                p ^= b[i];
                q ^= a[i];
            } else {
                p ^= a[i];
                q ^= b[i];
            }
        } else {
            if (q ^ a[i]) {
                p ^= b[i];
                q ^= a[i];
            } else {
                p ^= a[i];
                q ^= b[i];
            }
        }
    }

    if (p > q) cout << "Ajisai\n";
    else if (p < q) cout << "Mai\n";
    else cout << "Tie\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}