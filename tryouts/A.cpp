#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    
    vector<vector<int>> a(2, vector<int>(m, 0));
    
    for (int _ = 0; _ < n; ++_) {
        string s;
        cin >> s;
        
        for (int j = 0; j < m; ++j) {
            a[0][j] += (s[j] == '#');
            a[1][j] += (s[j] != '#');
        }
    }
    
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(m + 1, vector<int>(y + 1, 1e9)));
    dp[0][1][1] = a[0][0];
    dp[1][1][1] = a[1][0];
    
    for (int i = 1; i < m; ++i) {
        for (int k = 0; k < 2; ++k) {
            for (int j = 1; j <= y; ++j) {
                if (dp[k][i][j] == 1e9) continue;
                
                if (j < y) {
                    dp[k][i + 1][j + 1] = min(dp[k][i + 1][j + 1], dp[k][i][j] + a[k][i]);
                }
                
                if (j >= x) {
                    dp[1 - k][i + 1][1] = min(dp[1 - k][i + 1][1], dp[k][i][j] + a[1 - k][i]);
                }
            }
        }
    }
    
    int best = 1e9;
    
    for (int k = 0; k < 2; ++k) {
        for (int j = x; j <= y; ++j) {
            best = min(best, dp[k][m][j]);
        }
    }
    
    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}