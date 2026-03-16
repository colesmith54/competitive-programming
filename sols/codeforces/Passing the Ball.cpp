#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int l = 0;
    while (l < n && s[l] == 'R') ++l;
    
    cout << min(n, l + 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
