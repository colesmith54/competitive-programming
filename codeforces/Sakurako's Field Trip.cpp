// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    for (int i = 1; i < n/2; i++) {
        int j = n - i - 1;
        if (a[i - 1] == a[i] || a[j + 1] == a[j]) {
            swap(a[i], a[j]);
        }
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i-1] == a[i]) ans++;
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