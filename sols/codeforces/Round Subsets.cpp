#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<ll> a(n);
    vector<int> p2(n, 0), p5(n, 0);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ll curr = a[i];
        
        while (curr > 0 && curr % 5 == 0) {
            p5[i]++;
            curr /= 5;
        }
        
        curr = a[i];
        while (curr > 0 && curr % 2 == 0) {
            p2[i]++;
            curr /= 2;
        }
    }
    
    int max_fives = k * log(1e18) / log(5);
    
    vector<vector<int>> dp(k + 1, vector<int>(max_fives + 1, -1));
    dp[0][0] = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = k - 1; j >= 0; --j) {
            for (int l = max_fives - p5[i]; l >= 0; --l) {
                if (dp[j][l] != -1) {
                    dp[j + 1][l + p5[i]] = max(
                        dp[j + 1][l + p5[i]], 
                        dp[j][l] + p2[i]
                    );
                }
            }
        }
    }
    
    int ans = 0;
    for (int l = 0; l <= max_fives; ++l) {
        if (dp[k][l] != -1) {
            ans = max(ans, min(l, dp[k][l]));
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}