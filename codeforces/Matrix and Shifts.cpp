// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<string> g(n);
    for (auto& x : g) {
        cin >> x;
    }

    int max_diag = 0;
    int total_zeros = 0;
    for (int j = 0; j < n; j++) {
        int curr_diag = 0;
        int row = 0;
        int col = j;

        for (int k = 0; k < n; k++) {
            curr_diag += (g[row][col] - '0');
            row = (row + 1) % n;
            col = (col + 1) % n;
        }

        max_diag = max(max_diag, curr_diag);
        total_zeros += (n - curr_diag);
    }

    int swap_main_diag = n - max_diag;
    int zeroes_off_main = total_zeros - swap_main_diag;
    int swap_rest = ((n * n) - n) - zeroes_off_main;

    cout << swap_main_diag + swap_rest << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}