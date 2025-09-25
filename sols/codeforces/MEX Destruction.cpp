// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int zeros = 0;
    for (auto& x : a) {
        cin >> x;
        if (x == 0) zeros++;
    }

    if (zeros == 0) {
        cout << "1\n";
        return;
    }

    if (zeros == n) {
        cout << "0\n";
        return;
    }

    int l = 0, r = n - 1;
    while (l < n && a[l++] == 0) zeros--;
    while (r >= 0 && a[r--] == 0) zeros--;

    if (zeros > 0) cout << "2\n";
    else cout << "1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}