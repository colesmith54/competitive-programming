#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<double> a(n);
    for (auto& x : a) cin >> x;
    
    sort(a.rbegin(), a.rend());
    double avg = accumulate(a.begin(), a.end(), 0.0) / a.size();
    
    int ans = count_if(a.begin(), a.end(), [avg](int x) {
        return x > avg;
    });
    
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}