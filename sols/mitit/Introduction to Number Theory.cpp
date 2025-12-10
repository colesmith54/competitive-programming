#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    sort(a.begin(), a.end());
    vector<int> pre(n + 1, a.front()), suf(n + 1, a.back());

    int stop = n;
    for (int i = 0; i < n; ++i) {
        pre[i+1] = lcm(pre[i], a[i]);
        if (pre[i] / gcd(pre[i], a[i]) > INT_MAX / a[i]) stop = min(stop, i);
        suf[n-i-1] = gcd(suf[n-i], a[n-i-1]);
    }

    for (int i = 0; i <= stop; ++i) {
        if (suf[i] % pre[i] == 0) {
            cout << pre[i] << '\n';
            return;
        }
    }

    cout << "-1" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}