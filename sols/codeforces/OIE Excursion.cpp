#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    int curr = -1;
    int run = 1;
    
    for (int x : a) {
        if (x == curr) { if (++run == m) { cout << "NO\n"; return; }}
        else { curr = x; run = 1; }
    }
    
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}