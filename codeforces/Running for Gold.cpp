// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> pos(n + 1, vector<int>(5));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> pos[i][j];
        }
    }

    int w = 1;
    for (int i = 2; i <= n; i++) {
        int winner_wins = 0;
        for (int k = 0; k < 5; k++) {
            if (pos[w][k] < pos[i][k]) {
                winner_wins++;
            }
        }
        if (winner_wins < 3) {
            w = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i == w) continue;
        int winner_wins = 0;
        for (int k = 0; k < 5; k++) {
            if (pos[w][k] < pos[i][k]) {
                winner_wins++;
            }
        }
        if (winner_wins < 3) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << w << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}