#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    int ans = 0;
    bool zero = false;
    char prev = -1;

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            zero = true;
        } else {
            if (prev != '1') {
                ans += 1 + zero;
            }
            zero = false;
        }
        prev = s[i];
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