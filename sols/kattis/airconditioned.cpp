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

    int n;
    cin >> n;

    vii minions(n);

    for (int i = 0; i < n; i++) {
        cin >> minions[i].first >> minions[i].second;
    }

    sort(minions.begin(), minions.end(), [](const ii& a, const ii& b) {
        return a.second != b.second ? a.second < b.second : a.first < b.first;
    });

    int ans = 0;
    int highest = INT_MIN;

    for (const ii& minion : minions) {
        if (minion.first > highest) {
            highest = minion.second;
            ans++;
        }
    }

    cout << ans;
}