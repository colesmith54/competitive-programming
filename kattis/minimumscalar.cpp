// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

void solve() {
    int n;
    cin >> n;

    vector<ll> v1(n);
    vector<ll> v2(n);

    for (int i = 0; i < n; i++) cin >> v1[i];
    for (int i = 0; i < n; i++) cin >> v2[i];

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<int>());

    ll scalar = 0;
    for (int i = 0; i < n; i++) {
        scalar += v1[i] * v2[i];
    }

    cout << scalar << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}