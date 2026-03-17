#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    
    ll ab = lcm(a, b);
    ll bc = lcm(b, c);
    ll ac = lcm(a, c);
    ll abc = lcm(ab, c);
    
    ll alice = 6 * (m / a) - 3 * (m / ab) - 3 * (m / ac) + 2 * (m / abc);
    ll bobbb = 6 * (m / b) - 3 * (m / ab) - 3 * (m / bc) + 2 * (m / abc);
    ll carol = 6 * (m / c) - 3 * (m / ac) - 3 * (m / bc) + 2 * (m / abc);
    
    cout << alice << ' ' << bobbb << ' ' << carol << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}