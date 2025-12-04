#include <bits/stdc++.h>

using namespace std;

int attempt(vector<int> a, vector<int> b) {
    int n = a.size();
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

    if (p > q) return 1;
    else if (p < q) return -1;
    return 0;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    for (int k = 19; k >= 0; --k) {
        vector<int> na(n), nb(b);
        generate(na.begin(), na.end(), [&, i=0]() mutable { return (a[i++] >> k) & 1; });
        generate(nb.begin(), nb.end(), [&, i=0]() mutable { return (b[i++] >> k) & 1; });
        int res = attempt(na, nb);

        if (res == 1) {
            cout << "Ajisai\n";
            return;
        } else if (res == -1) {
            cout << "Mai\n";
            return;
        }
    }

    cout << "Tie\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}