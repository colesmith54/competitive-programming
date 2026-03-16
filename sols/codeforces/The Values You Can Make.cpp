#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> c(n);
    for (auto& x : c) cin >> x;
    
    vector<vector<vector<char>>> dp(2, vector<vector<char>>(501, vector<char>(501, 0)));
    dp[0][0][0] = 1;
    
    int prev = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l <= j; ++l) {
                // don't use this coin at all
                dp[1 - prev][j][l] |= dp[prev][j][l];
                
                if (c[i] <= j) {
                    // select coin in subset but not to make k
                    dp[1 - prev][j][l] |= dp[prev][j - c[i]][l];
                    
                    if (c[i] <= l) {
                        // select coin to make k
                        dp[1 - prev][j][l] |= dp[prev][j - c[i]][l - c[i]];
                    }
                }
            }
        }
        prev = 1 - prev;
    }
    
    vector<int> ans;
    for (int i = 0; i <= k; ++i) {
        if (dp[prev][k][i]) {
            ans.push_back(i);
        }
    }
    
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}