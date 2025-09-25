#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    unordered_map<int, int> f;

    int x;
    bool yes = false;

    while (n--) {
        cin >> x;
        if (f.count(x)) {
            if ((f[x] - n) > 1) {
                yes = true;
            }
        } else {
            f[x] = n;
        }
    }

    cout << (yes ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}