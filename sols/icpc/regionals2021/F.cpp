#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> v(n, 0);
    for (auto& x : v) {
        string s;
        cin >> s;
        
        int p = 0;
        for (char c : s) {
            if (c == 'T') {
                x |= (1 << p);
            }
            ++p;
        }
    }
    
    int best = 0;
    for (int i = 0; i < 1 << k; ++i) {
        int worst = k;
        
        for (int u : v) {
            int right = k - __builtin_popcount(u ^ i);
            worst = min(worst, right);
        }
        
        best = max(best, worst);
    }
    
    cout << best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}