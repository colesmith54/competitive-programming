#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<char> p(n, 0);
    bool good = true;
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        
        if (a > b) good = false;
        if (a + 1 == b) p[a] = 1;
    }
    
    if (!good) {
        cout << "-1\n";
        return;
    }
    
    int ans = count(p.begin() + 1, p.end(), 0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}