// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

struct State {
    int delegates;
    int needed;

    State(int d, int n) {
        delegates = d;
        needed = n;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s;
    cin >> s;

    vector<State> states;
    int d, c, f, u, n;
    int total_delegates = 0;

    for (int i = 0; i < s; i++) {
        cin >> d >> c >> f >> u;
        total_delegates += d;

        n = max(0, (c + f + u) / 2 - c + 1);
        if (n <= u) states.emplace_back(d, n);
    }

    vi dp(total_delegates + 1, INT_MAX);
    dp[0] = 0;

    for (State state : states) {
        for (int i = total_delegates - state.delegates; i >= 0; i--) {
            if (dp[i] == INT_MAX) continue;
            dp[i + state.delegates] = min(dp[i + state.delegates], dp[i] + state.needed);
        }
    }

    int needed_delegates = total_delegates / 2 + 1;
    int m = *min_element(dp.begin() + needed_delegates, dp.end());
    if (m == INT_MAX) cout << "impossible";
    else cout << to_string(m);
}