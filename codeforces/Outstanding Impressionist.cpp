// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n;
    cin >> n;
    
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];

    vector<int> bad(2 * n + 1, 0);
    vector<int> count(2 * n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (l[i] == r[i]) {
            bad[l[i]] = 1;
            count[l[i]]++;
        }
    }

    for (int i = 1; i <= 2 * n; i++) {
        bad[i] += bad[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        if (l[i] == r[i]) {
            if (count[l[i]] == 1) {
                cout << '1';
            } else {
                cout << '0';
            }
        } else {
            int b = bad[r[i]] - bad[l[i] - 1];
            if (b < r[i] - l[i] + 1) {
                cout << '1';
            } else {
                cout << '0';
            }
        }
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}