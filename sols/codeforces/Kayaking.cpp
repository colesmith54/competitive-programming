#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(2 * n);
    for (auto& x : a) cin >> x;

    sort(a.begin(), a.end());
    
    int ans = INT_MAX;
    
    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int j = i + 1; j < 2 * n; ++j) {
            int curr = 0;
            vector<int> rem;
            
            for (int k = 0; k < 2 * n; ++k) {
                if (k != i && k != j) {
                    rem.push_back(a[k]);
                }
            }
            
            for (int k = 0; k < rem.size(); k += 2) {
                curr += rem[k + 1] - rem[k];
            }
            
            ans = min(ans, curr);
        }
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}