// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

vi buildPi(string& s) {
    int n = (int) s.size();
    vi pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

void solve() {
    string a, b;
    cin >> a >> b;

    string combine = b + '#' + a;
    vi pi = buildPi(combine);
    int bsz = b.size();

    vi ans;
    for (int i = bsz + 1; i < pi.size(); i++) {
        if (pi[i] == bsz) {
            ans.push_back(i - (2 * bsz) + 1);
        }
    }

    if (ans.empty()) cout << "Not Found\n";
    else {
        cout << ans.size() << '\n';
        for (int& x : ans) cout << x << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}