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

    map<int, int> place1;
    map<int, int> place2;
    int x, t;

    for(int i = 0; i < n; i++) {
        cin >> x >> t;
        if (x < 0) place1[x] = t;
        else if (x > 0) place2[x] = t;
    }

    int ans = 0;

    if (!place1.empty()) {
        ans += (2 * abs(place1.begin()->first));
        int capacity = k;
        for (auto it = place1.begin(); it != place1.end(); it++) {
            while (it->second > 0) {
                int diff = min(capacity, it->second);
                it->second -= diff;
                capacity -= diff;

                if (capacity == 0 && it->second > 0) {
                    ans += (2 * abs(it->first));
                    capacity = k;
                }
            }
        }
    }

    if (!place2.empty()) {
        ans += (2 * place2.rbegin()->first);
        int capacity = k;
        for (auto it = place2.rbegin(); it != place2.rend(); it++) {
            while (it->second > 0) {
                int diff = min(capacity, it->second);
                it->second -= diff;
                capacity -= diff;

                if (capacity == 0 && it->second > 0) {
                    ans += (2 * abs(it->first));
                    capacity = k;
                }
            }
        }
    }

    cout << ans;
}