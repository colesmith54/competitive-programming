// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

void solve() {
    int n;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i = 0; i < n; ++i) {
        ll size;
        cin >> size;
        pq.push(size);
    }

    if (n == 1) {
        cout << "0\n";
        return;
    }

    ll ink = 0;
    while (pq.size() > 1) {
        ll first = pq.top(); pq.pop();
        ll second = pq.top(); pq.pop();

        ll merged = first + second;
        ink += merged;

        pq.push(merged);
    }

    cout << ink << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}