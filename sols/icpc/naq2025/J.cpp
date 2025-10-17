#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    for (int i = 0; i < 100; ++i) {
        cin >> x;
    }

    int ans = x % 10;
    if (ans == 0) cout << 10;
    else cout << ans;
}