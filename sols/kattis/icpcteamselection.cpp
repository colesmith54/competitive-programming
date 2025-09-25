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

    int p;
    deque<int> skill;

    for (int i = 0; i < 3 * n; i++) {
        cin >> p;
        skill.push_back(p);
    }

    sort(skill.begin(), skill.end());

    int S = 0;
    while (n--) {
        skill.pop_back();
        skill.pop_front();

        S += skill.back();
        skill.pop_back();
    }

    cout << S << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}