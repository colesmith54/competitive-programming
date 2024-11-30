// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    int plot;
    multiset<int> plots;

    for (int i = 0; i < n; i++) {
        cin >> plot;
        plots.insert(plot);
    }

    vector<double> houses(m + k);
    for (int i = 0; i < m; i++) cin >> houses[i];

    int side;
    for (int i = m; i < m + k; i++) {
        cin >> side;
        houses[i] = (sqrt(2.0) / 2.0) * side;
    }

    int ans = 0;
    for (int i = 0; i < m + k; i++) {
        auto it = plots.upper_bound(houses[i]);
        if (it == plots.end()) continue;

        plots.erase(it);
        ans++;
    }

    cout << ans;
}