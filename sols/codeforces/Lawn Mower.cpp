#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, w;
    cin >> n >> w;
    
    cout << n / w * (w - 1) + n % w << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
