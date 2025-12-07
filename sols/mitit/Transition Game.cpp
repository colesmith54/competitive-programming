#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> state(n + 1, 0);
    int cycles = 0;

    for (int i = 1; i <= n; ++i) {
        if (state[i] != 0) continue;

        int curr = i;
        vector<int> path;

        while (state[curr] == 0) {
            state[curr] = 1;
            path.push_back(curr);
            curr = a[curr];
        }

        if (state[curr] == 1) {
            bool cyc = false;
            for (int x : path) {
                if (x == curr) cyc = true;
                if (cyc) ++cycles;
                state[x] = 2;
            }
        } else {
            for (int x : path) {
                state[x] = 2;
            }
        }
    }

    cout << cycles << endl;
}