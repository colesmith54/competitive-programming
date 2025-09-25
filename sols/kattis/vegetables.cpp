// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double t;
    cin >> t;

    int n;
    cin >> n;

    auto cmp = [](const ii& a, const ii& b) {
        return ((double) a.first / a.second) < ((double) b.first / b.second);
    };

    priority_queue<ii, vii, decltype(cmp)> pq(cmp);

    int w;
    double min_w = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> w;
        pq.emplace(w, 1);
        min_w = min(min_w, (double) w);
    }

    int ans = 0;

    while (!pq.empty()) {
        auto curr = pq.top();
        if ((min_w / ((double)curr.first / curr.second)) >= t) break;

        pq.pop();
        pq.emplace(curr.first, curr.second + 1);

        min_w  = min(min_w, (double)curr.first / (curr.second + 1));
        ans++;
    }

    cout << ans;
}