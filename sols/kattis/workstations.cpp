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

    int n, m;
    cin >> n >> m;

    vii people(n);
    for (int i = 0; i < n; i++) {
        cin >> people[i].first >> people[i].second;
    }

    sort(people.begin(), people.end());
    multiset<int> workstations;

    int ans = 0;
    for (const ii& p : people) {
        auto it = workstations.lower_bound(p.first - m);
        if (it != workstations.end() && *it <= p.first) {
            workstations.erase(it);
            ans++;
        }
        workstations.insert(p.first + p.second);
    }

    cout << ans;
}