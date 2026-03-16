#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    if (find(a.begin(), a.end(), k) == a.end()) {
        cout << "no\n";
        return;
    }
    
    if (a.size() < 2) {
        cout << "yes\n";
        return;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n && j < i + 3; ++j) {
            if (a[i] >= k && a[j] >= k) {
                cout << "yes\n";
                return;
            }
        }
    }
    
    cout << "no\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
