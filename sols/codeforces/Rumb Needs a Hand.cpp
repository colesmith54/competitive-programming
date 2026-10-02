#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    for (auto& x : p) cin >> x;
    
    vector<int> bad;
    for (int i = 0; i < n; ++i) {
        if (p[i] != i + 1) {
            bad.push_back(p[i]);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (p[i] != i + 1) {
            if (bad.back() == i + 1) {
                bad.pop_back();
            } else {
                cout << "NO\n";
                return;
            }
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