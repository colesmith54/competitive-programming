// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

int dp(int idx, int last_jump, vi& fee, vvi& memo) {
    if (idx == memo.size() - 1) return fee[idx];
    if (idx <= 0 || idx >= memo.size()) return 1e9;
    
    if (memo[idx][last_jump] != -1) return memo[idx][last_jump];

    int opt1 = dp(idx - last_jump, last_jump, fee, memo);
    int opt2 = dp(idx + last_jump + 1, last_jump + 1, fee, memo);

    memo[idx][last_jump] = fee[idx] + min(opt1, opt2);
    return memo[idx][last_jump];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vi fee(n + 1);
    for (int i = 1; i <= n; i++) cin >> fee[i];

    vvi memo(n + 1, vi(n + 1, -1));
    cout << dp(2, 1, fee, memo);
}