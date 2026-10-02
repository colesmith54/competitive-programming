#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    if (k < n || k == 2 * n) {
        cout << "-1\n";
        return;
    }
    
    vector<vector<int>> a(n, vector<int>(n, 0));
    int curr = 1;
    
    for (int i = 0; i < n && k != 2 * n; ++i, ++k) {
        a[i][i] = curr++;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!a[i][j]) {
                a[i][j] = curr++;
            }
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}