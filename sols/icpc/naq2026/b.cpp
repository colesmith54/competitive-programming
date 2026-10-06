#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] - a[i - 1] > a[i + 1] - a[i]) {
            ++ans;
        }
    }
    
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}