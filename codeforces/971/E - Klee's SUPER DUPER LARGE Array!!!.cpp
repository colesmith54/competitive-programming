// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

void solve() {
    ll n, k;
    cin >> n >> k;

    ll total = n * (2 * k + n - 1) / 2;
    ll ans = LLONG_MAX;

    ll left = 1;
    ll right = n;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll sumL = mid * (2 * k + mid - 1) / 2;
        ll sumR = total - sumL;

        ll x = abs(sumL - sumR);
        ans = min(ans, x);

        if (sumL < sumR) {
            left = mid + 1;
        } else if (sumL > sumR) {
            right = mid - 1;
        } else {
            break;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}