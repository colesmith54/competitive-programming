// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
        x = max(x, a[0]);
    }

    sort(a.begin(), a.end());

    vector<int> b(m);
    for (auto& x : b) {
        cin >> x;
        if (x <= a[0]) x = INT_MAX;
    }

    sort(b.begin(), b.end(), greater<int>());

    for (auto& x : b) {
        x = a.end() - lower_bound(a.begin(), a.end(),x);
    }

    for (int k = 1; k <= m; k++) {
        ll sum = 0;
        for (int j = k - 1; j < m; j += k) {
            sum += b[j] + 1;
        }
        cout << sum << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}