#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    vector<int> a(200, 0);

    for (char c : t) ++a[c];
    for (char c : s) --a[c];

    string p;
    for (int i = 0; i < 200; ++i) {
        if (a[i] < 0) {
            cout << "Impossible\n";
            return;
        }

        if (a[i] > 0) {
            p += string(a[i], (char) i);
        }
    }

    sort(p.begin(), p.end());
    int l = 0, r = 0;
    string ans;

    while (l < s.size() && r < p.size()) {
        if (s[l] <= p[r]) {
            ans += s[l++];
        } else {
            ans += p[r++];
        }
    }

    while (l < s.size()) {
        ans += s[l++];
    }

    while (r < p.size()) {
        ans += p[r++];
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