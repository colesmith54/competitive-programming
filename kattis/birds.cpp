// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, d, n;
    cin >> l >> d >> n;

    vi birds(n + 2);

    for (int i = 0; i < n; i++) cin >> birds[i];
    birds[n] = 6 - d;
    birds[n+1] = l - 6 + d;

    sort(birds.begin(), birds.end());

    int ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        ans += max(0, ((birds[i] - birds[i-1]) / d) - 1);
    }

    cout << ans;
}