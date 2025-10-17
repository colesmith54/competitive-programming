#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    vector<ld> a(n);
    for (auto& x : a) cin >> x;

    sort(a.begin(), a.end());

    vector<ld> p1(n + 1, 0);
    vector<ld> p2(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        p1[i + 1] = p1[i] + a[i];
        p2[i + 1] = p2[i] + (a[i] * a[i]);
    }

    ld ans = numeric_limits<ld>::infinity();
    for (int i = 0; i + k <= n; ++i) {
        ld sum = p1[i + k] - p1[i];
        ld ss = p2[i + k] - p2[i];
        ld bad = ss - (sum * sum) / (ld)k;
        ans = min(ans, bad);
    }

    cout << fixed << setprecision(numeric_limits<ld>::max_digits10) << ans;
}