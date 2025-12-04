#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    x = abs(x);
    y = abs(y);

    string s;
    cin >> s;

    int diag = 0;
    int shift = 0;

    for (char c : s) {
        if (c == '4') {
            ++diag;
        } else if (c == '8') {
            diag += 2;
            ++shift;
        }
    }

    int b = diag - shift;
    if (x + y <= diag && max(x, y) <= b) {
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