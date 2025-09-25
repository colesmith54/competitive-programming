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

    int n, p;
    cin >> n >> p;

    int num, curr = 0, ans = 0;
    while (n--) {
        cin >> num;
        curr = max(0, curr + num - p);
        ans = max(ans, curr);
    }

    cout << ans;
}