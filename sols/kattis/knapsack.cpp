// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

void solve(int c, int n) {
    vii obj(n);
    for (int i = 0; i < n; i++) {
        cin >> obj[i].first >> obj[i].second;
    }

    vector<vector<int>> K(n + 1, vi(c + 1, 0));
    for (int i = 1; i <= n; i++) {
        int value = obj[i - 1].first;
        int weight = obj[i - 1].second;

        for (int w = 0; w <= c; w++) {
            if (weight <= w) {
                K[i][w] = max(value + K[i - 1][w - weight], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    int max_val = K[n][c];
    int w = c;

    vi path;
    for (int i = n; i > 0 && max_val > 0; i--) {
        if (max_val != K[i - 1][w]) {
            path.push_back(i - 1);
            max_val -= obj[i - 1].first;
            w -= obj[i - 1].second;
        }
    }

    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for (const int item : path) cout << item << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, n;
    while(cin >> c >> n) solve(c, n);
}
