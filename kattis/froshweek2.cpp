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

    int n, m;
    cin >> n >> m;

    vi t(n);
    for (int i = 0; i < n; i++) cin >> t[i];

    vi l(m);
    for (int i = 0; i < m; i++) cin >> l[i];

    int ans = 0;
    multiset<int> q(l.begin(), l.end());

    for (int i = 0; i < n; i++) {
        auto it = q.lower_bound(t[i]);
        if (it == q.end()) continue;

        q.erase(it);
        ans++;
    }

    cout << ans;
}