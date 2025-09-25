// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), t(n);
    for (auto& x_i : x) cin >> x_i;
    for (auto& t_i : t) cin >> t_i;

    vector<int> a;
    for (int i = 0; i < n; i++) {
        a.push_back(x[i] - t[i]);
        a.push_back(x[i] + t[i]);
    }

    int mn = a[0], mx = a[0];
    for (int val : a) {
        mn = min(mn, val);
        mx = max(mx, val);
    }

    int ans = (mn + mx);
    cout << ans / 2;
    if (ans % 2 != 0) cout << ".5";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}