#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct trip {
    int l, r;
    ll c;
};

void solve() {
    int n, x;
    cin >> n >> x;

    vector<trip> st(n);
    for (auto& t : st) {
        cin >> t.l >> t.r >> t.c;
    }

    vector<trip> en = st;

    sort(st.begin(), st.end(),[](const trip& a, const trip& b) {
         return a.l < b.l;
     });

    sort(en.begin(), en.end(), [](const trip& a, const trip& b) {
         return a.r < b.r;
     });
    
    vector<long long> best(x + 1, 2e18);
    long long ans = 2e18;
    int p = 0;

    for (const auto& curr : st) {
        while (p < n && en[p].r < curr.l) {
            int d = en[p].r - en[p].l + 1;
            if (d < x) best[d] = min(best[d], en[p].c);
            ++p;
        }

        int d = curr.r - curr.l + 1;
        int need = x - d;

        if (need > 0 && best[need] != 2e18) {
            ans = min(ans, curr.c + best[need]);
        }
    }

    cout << (ans == 2e18 ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}