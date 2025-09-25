// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve(vector<int>& x) {
    int n = (int)x.size();
    sort(x.begin(), x.end());
    return x[n / 2] - x[(n - 1) / 2] + 1;
}

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    cout << solve(x) * solve(y) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}