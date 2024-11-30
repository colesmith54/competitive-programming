// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

void solve(int n) {
    vi nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vi dp;
    vi idx;
    vi parent(n, -1);

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
        if (pos == dp.size()) {
            dp.push_back(nums[i]);
            idx.push_back(i);
        } else {
            dp[pos] = nums[i];
            idx[pos] = i;
        }

        if (pos != 0) parent[i] = idx[pos - 1];
    }

    int l = idx.size();
    cout << l << ' ';

    int k = idx[l-1];
    vi out;

    for (int i = l-1; i >= 0; i--) {
        out.push_back(nums[k]);
        k = parent[k];
    }

    reverse(out.begin(), out.end());
    for (const int x : out) cout << x << ' ';

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        solve(n);
    }
}