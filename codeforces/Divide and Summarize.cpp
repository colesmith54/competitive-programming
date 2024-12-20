// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> A(n);
    for (auto& x : A) cin >> x;

    set<ll> sums;
    function<void(vector<int>&)> quick_sort = [&](vector<int>& a) {
        if (a.empty()) return;

        ll total = 0;
        int mn = 1e9, mx = -1e9;
        for (int curr : a) {
            mn = min(mn, curr);
            mx = max(mx, curr);
            total += curr;
        }

        sums.insert(total);
        if (mn == mx) return;

        vector<int> l, r;
        int mid = (mx + mn) / 2;
        for (int curr : a) {
            if (curr <= mid) l.push_back(curr);
            else r.push_back(curr);
        }

        quick_sort(l);
        quick_sort(r);
    };

    quick_sort(A);

    while (q--) {
        int s;
        cin >> s;

        if (sums.count(s)) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}