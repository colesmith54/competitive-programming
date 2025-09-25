#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> x(n), y(n);

    for (int i = 0; i < n; ++i)
        cin >> x[i];

    for (int i = 0; i < n; ++i)
        cin >> y[i];

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x1 = x[i], x2 = x[j], y1 = y[i], y2 = y[j];
            ans = max(ans, (int) (pow(x2 - x1, 2) + pow(y2 - y1, 2)));
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}