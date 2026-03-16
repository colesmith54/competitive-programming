#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int num;
    vector<int> pos(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> num;
        pos[num] = i;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (pos[i] < pos[i-1]);
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