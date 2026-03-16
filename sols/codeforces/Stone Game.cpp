#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    auto p = min_element(a.begin(), a.end());
    auto q = max_element(a.begin(), a.end());

    int i = distance(a.begin(), p);
    int j = distance(a.begin(), q);

    if (i > j) {
        swap(i, j);
    }

    cout << min({j + 1, n - i, i + (n - j) + 1}) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}