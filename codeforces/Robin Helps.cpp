// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, k;
    cin >> n >> k;

    int coins = 0;
    int ans = 0;

    while (n--) {
        int a;
        cin >> a;

        if (a >= k) {
            coins += a;
        } else if (a == 0 && coins) {
            ++ans;
            --coins;
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