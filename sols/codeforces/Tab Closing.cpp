#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, n;
    cin >> a >> b >> n;

    int ans = 1;

    // awesome guess
    if (a > b && (double)a/n < b) ans = 2;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}