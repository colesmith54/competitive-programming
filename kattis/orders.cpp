// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vi c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    int m;
    cin >> m;

    vi sums(m);
    for (int i = 0; i < m; i++) cin >> sums[i];

    int max_sum = *max_element(sums.begin(), sums.end());

    vi ways(max_sum + 1, 0);
    vi parent(max_sum + 1, 0);

    ways[0] = 1;
    int coin;

    for (int i = 0; i < n; i++) {
        coin = c[i];
        for (int curr = c[i]; curr <= max_sum; curr++)  {
            if (ways[curr - coin] == 0) continue;
            ways[curr] = min(ways[curr] + ways[curr - coin], 2);
            parent[curr] = i;
        }
    }

    for (int s : sums) {
        if (ways[s] >= 2) {
            cout << "Ambiguous\n";
        } else if (ways[s] == 0) {
            cout << "Impossible\n";
        } else {
            vi output;
            while (s > 0) {
                output.push_back(parent[s] + 1);
                s -= c[parent[s]];
            }
            reverse(output.begin(), output.end());
            for (const int idx : output) {
                cout << idx << ' ';
            }
            cout << '\n';
        }
    }
}