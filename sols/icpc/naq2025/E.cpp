#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto cmp = [](vector<int>& a, vector<int>& b) {
        return pow(a[0] - 144, 2) + pow(a[1] - 84, 2)
            < pow(b[0] - 144, 2) + pow(b[1] - 84, 2);
    };

    int scoreR = 0;
    int scoreY = 0;

    for (int i = 0; i < 10; ++i) {
        int n;
        cin >> n;

        vector<vector<int>> stones;
        for (int j = 0; j < n; ++j) {
            int x, y;
            cin >> x >> y;
            stones.push_back({x, y, 0});
        }

        cin >> n;
        for (int j = 0; j < n; ++j) {
            int x, y;
            cin >> x >> y;
            stones.push_back({x, y, 1});
        }


        sort(stones.begin(), stones.end(), cmp);

        if (stones.empty()) {
            continue;
        }

        int winner = stones.front()[2];
        for (auto & stone : stones) {
            if (stone[2] != winner) {
                break;
            }

            if (winner == 0) ++scoreR;
            else if (winner == 1) ++scoreY;
        }
    }

    cout << scoreR << ' ' << scoreY;
}