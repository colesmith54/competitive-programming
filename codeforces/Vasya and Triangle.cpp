// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;

    bool even = k % 2 == 0;
    ll p = n * m;

    if (even) k /= 2;
    if (p % k != 0) {
        cout << "NO\n";
        return 0;
    }

    ll x = gcd(n, k);
    k /= x;
    ll a = n / x;

    x = gcd(m, k);
    k /= x;
    ll b = m / x;

    if (!even) {
        if (a < n) a += a;
        else b += b;
    }

    cout << "YES\n";
    cout << "0 0\n";
    cout << a << ' ' << 0 << '\n';
    cout << 0 << ' ' << b << '\n';
}