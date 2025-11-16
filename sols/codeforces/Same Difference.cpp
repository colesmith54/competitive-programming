#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans += (s[i] != s.back());
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}