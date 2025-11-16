#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, j, k;
    cin >> n >> j >> k;
    
    vector<int> d;
    while (n) {
        d.push_back(n % 10);
        n /= 10;
    }

    sort(d.begin(), d.end());
    vector<int> a = d;
    vector<int> b = d;

    while (--j) {
        next_permutation(a.begin(), a.end());
    }

    while (--k) {
        next_permutation(b.begin(), b.end());
    }

    int x = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == b[i]) {
            ++x;
        }
    }

    cout << x << 'A' << (a.size() - x) << 'B' << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}