#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    ll dash = 0;
    ll under = 0;

    while (n--) {
        char c;
        cin >> c;

        if (c == '-') ++dash;
        else if (c == '_') ++under;
    }

    ll dash1 = dash / 2;
    ll dash2 = dash / 2 + dash % 2;

    cout << dash1 * under * dash2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}