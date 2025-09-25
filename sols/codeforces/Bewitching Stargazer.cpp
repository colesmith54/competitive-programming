// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    ll n, k;
    cin >> n >> k;
    
    ll sum = 0, stage = 1, curr = n;
    while (curr >= k) {
        if (curr & 1) sum += stage;
        curr >>= 1;
        stage <<= 1;
    }

   cout << (((n + 1) * sum) / 2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}