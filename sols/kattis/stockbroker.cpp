// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d;
    cin >> d;

    vi prices(d);
    for (int i = 0; i < d; i++) cin >> prices[i];

    ll money = 100;
    ll shares = 0;

    for (int i = 0; i < d - 1; i++) {
        if (prices[i+1] > prices[i]) {
            ll buy = min(100000 - shares, money / prices[i]);
            shares += buy;
            money -= buy * prices[i];
        } else {
            money += shares * prices[i];
            shares = 0;
        }
    }

    money += shares * prices[d - 1];
    cout << money;
}