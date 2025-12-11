#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> b(n);
    for (auto& x : b) cin >> x;

    sort(b.begin(), b.end(), greater<int>());
    int sub = n - 1;
    for (int i = 0; i < n; ++i) {
        if (!sub) break;
        while (b[i] > 1 && sub > 0) {
            --b[i];
            --sub;
        }
    }

    int j = 0;
    while (sub--) --b[j++];

    sort(b.begin(), b.end());
    auto it = upper_bound(b.begin(), b.end(), 0);
    cout << distance(it, b.end()) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}