#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, p;
    cin >> n >> p;
    
    vector<int> b(n);
    for (auto& x : b) cin >> x;
    
    double tot = accumulate(b.begin(), b.end(), 0.0);
    double per = p / tot;
    
    double ans = 0;
    for (double s : b) {
        ans += per * s * per;
    }
    
    cout << fixed << setprecision(15) << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}