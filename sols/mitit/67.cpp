#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1, -1);
    for (int i = 1; i <= n-2; i += 3) {
        cout << "? " << i << ' ' << i+1 << endl;
        ll p; cin >> p;

        cout << "? " << i+1 << ' ' << i+2 << endl;
        ll q; cin >> q;

        a[i + 1] = gcd(p, q);
        a[i] = p / a[i + 1];
        a[i + 2] = q / a[i + 1];
    }

    if (a[n] == -1) {
        int i = n-2;
        ll p;

        if (a[n-1] == -1) {
            cout << "? " << i << ' ' << i + 1 << endl;
            cin >> p;
        }

        cout << "? " << i+1 << ' ' << i+2 << endl;
        ll q; cin >> q;

        if (a[n-1] == -1) {
            a[i + 1] = gcd(p, q);
            a[i] = p / a[i + 1];
        }

        a[i + 2] = q / a[i + 1];
    }

// n = 5
// 7 11 6 5 17

    cout << "! ";
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}