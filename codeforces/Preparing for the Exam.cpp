// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m);
    for (auto& x : a) cin >> x;

    vector<int> ans(m, 0);

    set<int> missing;
    for (int i = 1; i <= n; i++) missing.insert(i);

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        missing.erase(x);
    }

    for (int i = 0; i < m; i++) {
        if (missing.empty() || (missing.size() == 1 && missing.count(a[i])))
            ans[i] = 1;
    }

    for (int x : ans) cout << x;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}