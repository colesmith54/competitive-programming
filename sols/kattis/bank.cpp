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

    int n, t;
    cin >> n >> t;

    vii people(n);
    for (int i = 0; i < n; i++) {
        cin >> people[i].first >> people[i].second;
    }

    sort(people.begin(), people.end(), greater<ii>());
    vi slots(t+1, 0);

    for (auto& [cash, time] : people) {
        while (time && slots[time] != 0) time--;
        if (slots[time] == 0) slots[time] = cash;
    }

    int ans = accumulate(slots.begin(), slots.end(), 0);
    cout << ans;
}