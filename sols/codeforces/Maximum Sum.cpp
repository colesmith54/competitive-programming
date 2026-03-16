#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    ll total_sum = 0;
    ll curr_sum = 0;
    ll max_sum = 0;
    
    for (int x : a) {
        curr_sum = max(curr_sum + x, 0LL);
        max_sum = max(max_sum, curr_sum);
        total_sum += x;
    }
    
    int p = 1;
    while (k--) {
        p = (p * 2) % MOD;
    }

    max_sum = (max_sum + MOD) % MOD;
    total_sum = (total_sum + MOD) % MOD;
    
    int ans = (total_sum + (max_sum * p) - max_sum + MOD) % MOD;
    cout << (ans + MOD) % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}