// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct Event {
    int idx;
    bool type;

    Event(int i, char tp) {
        idx = i;
        type = (tp == '+');
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<Event> events;
    vector<int> l(n, 0);

    while (q--) {
        int idx; char tp;
        cin >> idx >> tp; idx--;
        events.emplace_back(idx, tp);
        if (tp == '+') l[idx]++;
    }

    auto dist = [&](int i, int j) -> int {
        int curr = 0, ans = 0;
        for (const Event& e : events) {
            if (e.idx == j && !e.type) curr++;
            if (e.idx == i && e.type) curr--;
            ans = min(ans, curr);
        }
        return 1 - ans;
    };


    vector<vector<int>> d(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            else d[i][j] = dist(i, j);
        }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) dp[1 << i][i] = 1;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (dp[mask][i] == INT_MAX) continue;
            for (int j = 0; j < n; j++) {
                if ((mask >> j) & 1) continue;
                int nmask = mask | (1 << j);
                dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + d[i][j]);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp.back()[i] + l[i]);
    }

    cout << ans << '\n';
}