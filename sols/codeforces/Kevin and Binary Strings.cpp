// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int first_zero = 0;
    while (first_zero < n && s[first_zero] != '0') first_zero++;

    if (first_zero == n) {
        cout << 1 << ' ' << 1 << ' ' << 1 << ' ' << n << '\n';
        return;
    }

    string match = s.substr(first_zero);
    int k = match.size();

    auto uncommon = [&] (const string& s, const string& t) -> int {
        int p = 0;
        while (p < k && s[p] != t[p]) p++;
        return p;
    };

    int p = 0;
    int l = 1;
    int r = 1;
    for (int i = 0; i + k <= s.size(); i++) {
        string curr = s.substr(i, k);
        int pre = uncommon(match, curr);

        if (pre > p){
            p = pre;
            l = i + 1;
            r = i + k;
        }
    }

    cout << 1 << ' ' << n << ' ' << l << ' ' << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}