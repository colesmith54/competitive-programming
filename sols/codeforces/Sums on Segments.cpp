// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

pair<int, int> kadane(vector<int>& nums) {
    if (nums.empty()) return {0, 0};

    int ans_max = INT_MIN, ans_min = INT_MAX;
    int curr_max = 0, curr_min = 0;

    for (int num : nums) {
        curr_max = max(curr_max + num, num);
        curr_min = min(curr_min + num, num);

        ans_max = max(curr_max, ans_max);
        ans_min = min(curr_min, ans_min);
    }

    return {ans_min, ans_max};
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int special = 0;
    while (special < n && abs(a[special]) == 1) special++;

    if (special == n) {
        a.push_back(0);
        n++;
    }

    vector<pair<int, int>> itv;
    itv.emplace_back(0, 0);

    vector<int> l(a.begin(), a.begin() + special);
    vector<int> r(a.begin() + special + 1, a.end());

    auto [minL, maxL] = kadane(l);
    auto [minR, maxR] = kadane(r);

    itv.emplace_back(minL, maxL);
    itv.emplace_back(minR, maxR);

    int minLS = 0, maxLS = 0, currLS = 0;
    for (int i = special - 1; i >= 0; i--) {
        currLS += a[i];
        minLS = min(currLS, minLS);
        maxLS = max(currLS, maxLS);
    }

    int minRP = 0, maxRP = 0, currRP = 0;
    for (int i = special + 1; i < n; i++) {
        currRP += a[i];
        minRP = min(currRP, minRP);
        maxRP = max(currRP, maxRP);
    }

    itv.emplace_back(minLS + a[special] + minRP, maxLS + a[special] + maxRP);
    sort(itv.begin(), itv.end());
    vector<pair<int, int>> merged;

    for (auto& [L, R] : itv) {
        if (L > R) continue;
        if (merged.empty()) merged.emplace_back(L, R);
        else {
            auto& prev = merged.back();
            if (L <= prev.second + 1) {
                prev.second = max(prev.second, R);
            } else {
                merged.emplace_back(L, R);
            }
        }
    }

    vector<int> ans;
    for (auto& [L, R] : merged) {
        for (int i = L; i <= R; i++) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << '\n';
    for (auto& x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}