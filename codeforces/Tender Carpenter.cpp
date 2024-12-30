// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int prev = a[0];
    for (int i = 1; i < n; i++) {
        if (2 * a[i] > prev && 2 * prev > a[i]) {
            cout << "YES\n";
            return;
        }
        prev = a[i];
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}