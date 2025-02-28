#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n - 2);
    for (auto& x : a) cin >> x;

    for (int i = 0; i < n - 4; ++i) {
        if (a[i] == 1 && a[i + 1] == 0 && a[i + 2] == 1) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}