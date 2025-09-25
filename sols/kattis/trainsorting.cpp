// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

int LIS(int s, vi& _a, bool de) {
    vi dp;
    for (int i = s; i < _a.size(); i++) {
        int a = (de) ? -_a[i] : _a[i];
        auto it = lower_bound(dp.begin(), dp.end(), a);
        if (!dp.empty() && it == dp.begin()) continue;
        if (it != dp.end()) *it = a;
        else dp.push_back(a);
    }
    return dp.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vi trains(n);
    for (int i = 0; i < n; i++) cin >> trains[i];

    if (n == 0) {
        cout << "0";
        return 0;
    }

    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, LIS(i, trains, false) + LIS(i, trains, true) - 1);
    }

    cout << ans;
}