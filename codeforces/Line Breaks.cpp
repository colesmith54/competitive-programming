// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (auto& x : s) cin >> x;

    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (int)s[i].size();
        if (sum > m) break;
        ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}