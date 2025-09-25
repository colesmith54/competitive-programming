#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a > b) swap(a, b);

    int m = min(a, b);
    int one = a - m + 1;
    int two = b - m + 1;

    int n = 2 * (two - one);
    if (a > n || b > n || c > n || a == b || n % 2) {
        cout << "-1\n";
        return;
    }

    int op1 = c - n / 2;
    int op2 = c + n / 2;

    if (op1 > 0 && op1 != a && op1 != b) cout << op1 << '\n';
    else if (op2 <= n && op2 != a && op2 != b) cout << op2 << '\n';
    else cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}