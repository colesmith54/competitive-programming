#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 1 && j == 0) cout << 'C';
            else if (i == 0 && j == 1) cout << 'C';
            else cout << '.';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}