#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    if (a.front() == -1 || a.back() == -1) {
        cout << "0\n";

        if (a.front() == -1 && a.back() == -1) {
            a.front() = 0;
            a.back() = 0;
        } else if (a.front() == -1) {
            a.front() = a.back();
        } else {
            a.back() = a.front();
        }

        for (int x : a) {
            cout << ((x == -1) ? 0 : x) << ' ';
        }
    } else {
        int diff = 0;
        for (int i = 0; i < n - 1; ++i) {
            diff += a[i + 1] - a[i];
        }

        cout << abs(diff) << '\n';
        for (int x : a) {
            cout << ((x == -1) ? 0 : x) << ' ';
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