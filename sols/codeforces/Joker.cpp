// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<ii> itv;
    itv.emplace_back(m, m);

    while (q--) {
        int a_i;
        cin >> a_i;

        vector<ii> next;

        for(auto &[l, r] : itv){
            if (a_i >= l && a_i <= r) {
                next.emplace_back(1, 1);
                next.emplace_back(n, n);

                if (l < a_i) {
                    next.emplace_back(l, a_i - 1);
                    next.emplace_back(l + 1, a_i);
                }

                if (a_i < r) {
                    next.emplace_back(a_i + 1, r);
                    next.emplace_back(a_i, r - 1);
                }
            } else if (a_i < l) next.emplace_back(max(l-1, 1), r);
            else next.emplace_back(l, min(r+1, n));
        }

        sort(next.begin(), next.end());

        vector<ii> merged;
        for(auto& [l, r] : next){
            if (merged.empty()) merged.emplace_back(l, r);
            else {
                auto &[ll, lr] = merged.back();
                if (l <= lr + 1) merged.back().second = max(lr, r);
                else merged.emplace_back(l, r);
            }
        }

        itv = merged;
        int ans = 0;
        for (auto& [l, r] : itv) ans += (r - l + 1);
        cout << ans << ' ';
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
