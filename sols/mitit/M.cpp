#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == 0 || j == n-1) {
                cout << '#';
                continue;
            }

            if (i <= n/2 && (j == i || j == n-i-1)) {
                cout << '#';
                continue;
            }

            cout << '.';
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