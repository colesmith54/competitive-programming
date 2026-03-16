#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 1) {
        cout << "0";
        return 0;
    }

    vi nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    unordered_set<int> unique(nums.begin(), nums.end());
    if (unique.size() == n) {
        cout << "0";
        return 0;
    }

    int ans = n;
    unordered_map<int, int> freq;

    for (int i = -1, j; i < n; i++) {
        if (i >= 0 && ++freq[nums[i]] == 2) break;
        bool good = true;

        for (j = n-1; j > i; j--) {
            if (freq[nums[j]]) {
                ans = min(ans, j - i);
                while (j++ < n) freq[nums[j]]--;
                good = false; break;
            }
            freq[nums[j]]++;
        }

        if (good) ans = min(ans, j - i + 1);
    }

    cout << ans;
};