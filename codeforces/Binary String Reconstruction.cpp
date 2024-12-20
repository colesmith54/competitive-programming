// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    int x;
    cin >> x;

    string w(n, '1');

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') continue;
        if (i-x >= 0) w[i-x] = '0';
        if (i+x < n) w[i+x] = '0';
    }

    string _s(n, '0');
    for (int i = 0; i < n; i++) {
        bool l = (i-x >= 0 && w[i-x] == '1');
        bool r = (i+x < n && w[i+x] == '1');
        if (l || r) _s[i] = '1';
    }

    if (s == _s) cout << w << '\n';
    else cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}