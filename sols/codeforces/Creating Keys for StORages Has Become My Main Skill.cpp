#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a;
    int mask = 0;
    for (int i = 0; i < n; ++i) {
        if ((i | x) == x) {
            a.push_back(i);
            mask |= i;
        } else {
            // oops, ur mex is cooked
            break;
        }
    }

    if (mask != x) {
        if (a.size() == n) a.pop_back();
        a.push_back(x);
    }

    while (a.size() < n) a.push_back(x);
    for (auto& ax : a) cout << ax << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}