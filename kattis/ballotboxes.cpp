// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

void solve(int n, int b) {
    auto cmp = [](const ii& a, const ii& b) {
        return (a.first / (double) a.second) < (b.first / (double) b.second);
    };
    priority_queue<ii, vii, decltype(cmp)> pq(cmp);

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.emplace(a, 1);
    }
    b -= n;

    ii curr;
    while (b--) {
        curr = pq.top(); pq.pop();
        pq.emplace(curr.first, curr.second + 1);
    }

    cout << ceil(pq.top().first / (double) pq.top().second) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b;
    while (cin >> n >> b) {
        if (n == -1 || b == -1) break;
        solve(n, b);
    }
}