// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int total = a + b + c;
    int ans = 0;

    if (n >= total) {
        int cycles = n / total;
        n -= cycles * total;
        ans += (3 * cycles);
    }

    if (n > 0) {
        n -= a;
        ans++;
    }

    if (n > 0) {
        n -= b;
        ans++;
    }

    if (n > 0) {
        n -= c;
        ans++;
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