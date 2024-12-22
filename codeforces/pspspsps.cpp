// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> up(n, n);
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'p') {
            for (int j = 0; j < i; j++) {
                up[j] = min(up[j], i);
            }
        } else if (s[i-1] == 's') {
            int lim = n-i+1;
            for (int j = i-1; j < n; j++) {
                up[j] = min(up[j], lim);
            }
        }
    }

    sort(up.begin(), up.end());
    bool good = true;

    for (int i = 1; i <= n; i++) {
        if (i > up[i - 1]) {
            good = false;
            break;
        }
    }

    if (good) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}