#include <bits/stdc++.h>

using namespace std;

void solve() {
    int t, n;
    cin >> t >> n;
    
    double s = 1.0 / tan(3.14159265358979323846264338 * t / 180.0);
    
    int x, h;
    vector<pair<double, double>> itv;
    
    while (n--) {
        cin >> x >> h;
        itv.emplace_back(x, x + s * h);
    }
    
    sort(itv.begin(), itv.end());
    vector<pair<double, double>> itv2;
    
    for (auto& [st, en] : itv) {
        if (itv2.empty() || st > itv2.back().second) {
            itv2.emplace_back(st, en);
        } else {
            itv2.back().second = max(itv2.back().second, en);
        }
    }
    
    double ans = 0;
    for (auto& [st, en] : itv2) {
        ans += en - st;
    }
    
    cout << fixed << setprecision(15) << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}