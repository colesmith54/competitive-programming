// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> c(n);
    for (auto& x : c) cin >> x;

    vector<int> curr(n);
    iota(curr.begin(), curr.end(), 1);

    vector<int> idx(n + 1);
    iota(idx.begin(), idx.end(), -1);

    vector<pair<int, int>> ans;

    for (int i = n-1; i >= 0; i--) {
        int val = c[i];
        int curr_pos = idx[val];
        for (int j = curr_pos-1; j >= 0; j--) {
            int to_swap = curr[j];
            ans.emplace_back(val, to_swap);
            curr[j] = val; curr[j+1] = to_swap;
            idx[val]--; idx[to_swap]++;
        }

        while (idx[val] != i) {
            int j = idx[val] + 1;
            int to_swap = curr[j];
            ans.emplace_back(to_swap, val);
            curr[j-1] = to_swap; curr[j] = val;
            idx[to_swap]--; idx[val]++;
        }
    }

    cout << ans.size() << '\n';
    for (auto& [x, y] : ans) cout << x << ' ' << y << '\n';
}