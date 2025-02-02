#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int max_k = log2(n);
    for (int k = 2; k <= max_k; ++k) {
        int p = pow(2, k) - 1;
        if (n % p) continue;

        int x = n / p;
        cout << x << '\n';
        return;
    }

    cout << "1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}