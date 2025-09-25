// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    for (int l = 0; l < n - 1; l++) {
        if (s[l] == s[l + 1]) {
            cout << s.substr(l, 2) << '\n';
            return;
        }
    }

    for (int l = 0; l < n - 2; l++) {
        if (s[l] != s[l + 1] && s[l + 1] != s[l + 2] && s[l] != s[l + 2]) {
            cout << s.substr(l, 3) << '\n';
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}