// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    cin >> n >> h;

    vi stalagmites(n/2);
    vi stalactites(n/2);

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) cin >> stalagmites[i/2];
        else cin >> stalactites[i/2];
    }

    sort(stalagmites.begin(), stalagmites.end());
    sort(stalactites.begin(), stalactites.end());

    int ans = INT_MAX;
    int num = 0;

    for (int height = 1; height <= h; height++) {
        int a = stalagmites.end() - lower_bound(stalagmites.begin(), stalagmites.end(), height);

        int threshold = h - height + 1;
        int b = stalactites.end() - lower_bound(stalactites.begin(), stalactites.end(), threshold);

        int total = a + b;

        if (total < ans) {
            ans = total;
            num = 1;
        } else if (total == ans) {
            num++;
        }
    }

    cout << ans << ' ' << num;
}