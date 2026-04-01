#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    bool ans = count(s.begin(), s.end(), 'Y') < 2;
    cout << (ans ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}