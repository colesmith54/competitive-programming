#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    vector<int> ops;
    
    for (int i = 0; i < 31; ++i) {
        bool bit = a & (1 << i);
        bool cmp = b & (1 << i);

        if (bit == cmp) continue;

        if (bit && !cmp) {
            ops.push_back(1 << i);
            a ^= (1 << i);
        } else if (!bit && cmp && a > (1 << i)) {
            ops.push_back(1 << i);
            a ^= (1 << i);
        } else {
            cout << "-1" << '\n';
            return;
        }
    }

    cout << ops.size() << '\n';
    if (ops.size()) {
        for (int x : ops) cout << x << ' ';
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