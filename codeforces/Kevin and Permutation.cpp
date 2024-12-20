// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n, 0);
    int curr = 1;

    for (int i = k - 1; i < n; i += k) {
        p[i] = curr++;
    }

    for (int i = 0; i < n; i++) {
        if (!p[i]) {
            p[i] = curr++;
        }
    }

    for (auto& x : p) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}