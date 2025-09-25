// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;

void solve() {
    int n;
    cin >> n;

    vi dvd(n);
    for(int i = 0; i < n; i++) cin >> dvd[i];

    int expected = 1;
    for(int i = 0; i < n; i++) {
        if(dvd[i] == expected){
            expected++;
        }
    }

    cout << n - expected + 1 << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    while (k--) solve();
}