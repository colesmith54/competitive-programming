// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

void solve() {
    int l, n;
    cin >> l >> n;

    vi ants(n);
    for (int i = 0; i < n; i++) cin >> ants[i];
    sort(ants.begin(), ants.end(), [&](const int& a, const int& b) {
        return abs(a - (l / 2.0f)) < abs(b - (l / 2.0f));
    });

    cout << min(l - ants[0], ants[0]) << ' ' << max(ants[n-1], l - ants[n-1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}