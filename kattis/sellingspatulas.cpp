// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

void solve(int n) {
    vector<double> profit(1500, -0.08);

    int time;
    double price;
    for (int i = 0; i < n; i++) {
        cin >> time >> price;
        profit[time] += price;
    }

    double sum = 0, ans = 0;
    int curr_start = 0, curr_len = -1;
    int start = -1, len = -1;

    for (int i = 0; i < 1500; i++) {
        curr_len++;
        sum += profit[i];

        if (sum > ans ||
                (sum == ans && curr_len < len) ||
                (sum == ans && curr_len == len && curr_start < start)) {
            ans = sum;
            len = curr_len;
            start = curr_start;
        }

        if (sum < 1e-9) {
            sum = 0;
            curr_start = i + 1;
            curr_len = -1;
        }
    }

    if (ans <= 0) {
        cout << "no profit\n";
    } else {
        cout << fixed << setprecision(2) << ans << ' ' << start << ' ' << start + len << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && (n != 0)) solve(n);
}