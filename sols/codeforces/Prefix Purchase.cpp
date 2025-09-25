// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (auto& x : c) cin >> x;

    vector<int> m(n);
    m[n - 1] = c[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        m[i] = min(m[i + 1], c[i]);
    }

    int k;
    cin >> k;

    vector<int> ans(n, 0);
    for (int i = 0; i < n - 1; i++) {
        if (m[i + 1] <= c[i]) continue;

        int ops = k / c[i];
        int replacements = (k % c[i]) / (m[i + 1] - c[i]);
        ans[i] = max(0, ops - replacements);
        k -= ans[i] * c[i];
    }

    ans[n - 1] = k / c[n - 1];
    for (int i = n - 2; i >= 0; i--) ans[i] += ans[i + 1];
    for (auto& x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}