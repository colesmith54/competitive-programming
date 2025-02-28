#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int a = n / 15;
    int ans = a * 3;

    int r = n % 15;
    if (r >= 0) ans += min(3, r + 1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}