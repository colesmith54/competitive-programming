#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) cin >> p[i];

    vector<int> state(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (state[i] != -1) continue;

        int j = 0;
        int curr = i;

        while (state[p[curr]] == -1) {
            state[curr] = j;
            j = 1 - j;
            curr = p[curr];
        }

        state[curr] = (state[p[curr]] == j) ? 2 : j;
    }

    vector<char> color = {'R', 'G', 'B'};
    for (int i = 1; i <= n; ++i) {
        cout << color[state[i]];
    }

    cout << '\n';
}

// represent as deque, color each level different color

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}