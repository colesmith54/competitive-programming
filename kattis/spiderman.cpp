#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m;
    cin >> m;

    vector<int> jumps(m);
    int total_sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> jumps[i];
        total_sum += jumps[i];
    }

    int left = 0, right = total_sum;
    int answer = -1;

    while (left <= right) {
        int K = (left + right) / 2;
        vector<vector<bool>> dp(m + 1, vector<bool>(K + 1, false));
        dp[0][0] = true;

        for (int idx = 0; idx < m; idx++) {
            for (int pos = 0; pos <= K; pos++) {
                if (!dp[idx][pos]) continue;
                int up_pos = pos + jumps[idx];
                if (up_pos <= K) {
                    dp[idx + 1][up_pos] = true;
                }
                int down_pos = pos - jumps[idx];
                if (down_pos >= 0) {
                    dp[idx + 1][down_pos] = true;
                }
            }
        }

        if (dp[m][0]) {
            answer = K;
            right = K - 1;
        } else {
            left = K + 1;
        }
    }

    if (answer == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<vector<bool>> dp(m + 1, vector<bool>(answer + 1, false));
        vector<vector<char>> parent(m + 1, vector<char>(answer + 1, ' '));
        dp[0][0] = true;

        for (int idx = 0; idx < m; idx++) {
            for (int pos = 0; pos <= answer; pos++) {
                if (!dp[idx][pos]) continue;

                int up_pos = pos + jumps[idx];
                if (up_pos <= answer && !dp[idx + 1][up_pos]) {
                    dp[idx + 1][up_pos] = true;
                    parent[idx + 1][up_pos] = 'U';
                }

                int down_pos = pos - jumps[idx];
                if (down_pos >= 0 && !dp[idx + 1][down_pos]) {
                    dp[idx + 1][down_pos] = true;
                    parent[idx + 1][down_pos] = 'D';
                }
            }
        }

        string path;
        int pos = 0;

        for (int idx = m; idx > 0; idx--) {
            char move = parent[idx][pos];
            path += move;
            if (move == 'U') {
                pos -= jumps[idx - 1];
            } else {
                pos += jumps[idx - 1];
            }
        }

        reverse(path.begin(), path.end());
        cout << path << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) solve();
}
