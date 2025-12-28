#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ans = 0;
    while (!s.empty()) {
        int idx = s.find_last_of('1');

        if (idx == string::npos) {
            ans += s.size();
            break;
        }

        int chunk = s.size() - idx;
        int sleep = max(0, chunk - k - 1);
        ans += sleep;

        while (chunk--) {
            s.pop_back();
        }
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