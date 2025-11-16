#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a;
    cin >> n >> a;
    
    int l = 0, r = 0;
    while (n--) {
        int x;
        cin >> x;

        if (x < a) ++l;
        else if (x > a) ++r;
    }

    cout << ((r > l) ? a+1 : a-1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}