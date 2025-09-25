#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int m = 998244353;

    vector<int> p(n + 1);
    vector<vector<int>> g(n + 1);

    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        g[p[i]].push_back(i);
    }

    queue<int> q;
    q.push(1);

    vector<vector<int>> lvls;

    while (!q.empty()) {
        int s = q.size();
        lvls.push_back({});

        while (s--) {
            int u = q.front(); q.pop();
            lvls.back().push_back(u);
            for (int v : g[u]) q.push(v);
        }
    }

    int l = lvls.size();
    if (l == 1) {
        cout << '1' << '\n';
        return;
    }

    vector<ll> dp(n + 1, 0);
    vector<ll> dp_lvl(l, 0);

    dp[1] = 1;
    dp_lvl[0] = 1;
    dp_lvl[1] = lvls[1].size();

    for (int v : lvls[1]) dp[v] = 1;

    for (int i = 2; i < l; ++i) {
        ll sum = 0;
        for (int v : lvls[i]) {


            sum = (sum + dp[v]) % m;
        }
        dp_lvl[i] = sum;
    }

    ll ans = 0;
    for (int i = 0; i < l; ++i) {
        ans = (ans + dp_lvl[i]) % m;
    }

    cout << ans % m << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}