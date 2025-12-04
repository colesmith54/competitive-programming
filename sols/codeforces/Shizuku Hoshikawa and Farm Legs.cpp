#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    if ((n % 4) % 2) {
        cout << "0\n";
        return;
    }

    cout << (n / 4) + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}