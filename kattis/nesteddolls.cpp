// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

void solve() {
    int m;
    cin >> m;

    vii dolls(m);
    for (int i = 0; i < m; i++) {
        cin >> dolls[i].first >> dolls[i].second;
    }

    sort(dolls.begin(), dolls.end(), [](const ii& a, const ii& b) {
        return (a.first == b.first) ? a.second > b.second : a.first < b.first;
    });

    vi dp;
    for (const auto& [w, h] : dolls) {
        auto it = upper_bound(dp.begin(), dp.end(), -h);
        if (it != dp.end()) {
            *it = -h;
        } else {
            dp.push_back(-h);
        }
    }

    cout << dp.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}