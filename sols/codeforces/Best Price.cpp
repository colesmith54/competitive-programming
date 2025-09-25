// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n), p;
    for (auto& x : a) {
        cin >> x;
        p.push_back(x);
    }
    for (auto& x : b) {
        cin >> x;
        p.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    ll ans = 0;

    for (int price : p) {
        int cnt_b = n - (lower_bound(b.begin(), b.end(), price) - b.begin());
        int cnt_a = n - (lower_bound(a.begin(), a.end(), price) - a.begin());

        if (cnt_b - cnt_a <= k) {
            ans = max(ans, (ll) price * cnt_b);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}