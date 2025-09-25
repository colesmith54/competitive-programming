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

    int n, k;
    cin >> n >> k;

    vii activities(n);
    for (int i = 0; i < n; i++) {
        cin >> activities[i].first >> activities[i].second;
    }

    sort(activities.begin(), activities.end(), [](const ii& a, const ii& b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });

    int ans = 0;
    multiset<int> rooms;
    for (int i = 0; i < k; i++) rooms.insert(INT_MIN);

    for (auto& [s, f] : activities) {
        auto it = rooms.lower_bound(s);
        if (it == rooms.begin()) continue;

        rooms.erase(--it);
        rooms.insert(f);
        ans++;
    }

    cout << ans;
}