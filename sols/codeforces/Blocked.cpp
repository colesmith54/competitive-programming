#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    sort(a.rbegin(), a.rend());
    
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1]) {
            cout << "-1\n";
            return;
        }
    }
    
    for (int x : a) cout << x << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}