#include <bits/stdc++.h>

using namespace std;
using ld = long double;

struct Orc {
    ld r, t;
};

void solve() {
    int n, k;
    cin >> n >> k;

    const ld pi = acos(-1.0);
    vector<Orc> orcs(n);

    for (auto &p : orcs) {
        int x, y;
        cin >> x >> y;

        p.r = hypot(x, y);
        p.t = atan2(y, x);
        if (p.t < 0) p.t += 2 * pi;
    }

    vector<pair<ld, int>> e;

    auto possible = [&](ld r) {
        e.clear();
        int curr = 0;

        for (const auto &p : orcs) {
            if (p.r > 2 * r) continue;

            ld d = acos(min((ld)1.0, p.r / (2 * r)));
            ld l = p.t - d;
            ld ri = p.t + d;

            if (l < 0) l += 2 * pi;
            if (ri >= 2 * pi) ri -= 2 * pi;

            e.emplace_back(l, 1);
            e.emplace_back(ri, -1);

            if (l > ri) ++curr;
        }

        if (curr >= k) return true;

        sort(e.begin(), e.end(),[](auto &a, auto &b) {
             if (a.first != b.first) return a.first < b.first;
             return a.second > b.second;
         });

        for (auto [_, d] : e) {
            curr += d;
            if (curr >= k) return true;
        }

        return false;
    };

    ld l = 0;
    ld r = 2e9;

    if (!possible(r)) {
        cout << -1 << '\n';
        return;
    }

    int idk_man = 100;
    while (idk_man--) {
        ld m = l + (r - l) / 2;
        if (possible(m)) r = m;
        else l = m;
    }

    cout << fixed << setprecision(15) << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}