#include <bits/stdc++.h>

using namespace std;

void solve() {
    string r;
    cin >> r;
    
    int ans = 0;
    
    ans += r.front() == 'u';
    r.front() = 's';
    
    ans += r.back() == 'u';
    r.back() = 's';
    
    for (int i = 2; i < r.size() - 1; ++i) {
        if (r.substr(i - 2, 3) == "suu") {
            r[i] = 's';
            ++ans;
        }
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