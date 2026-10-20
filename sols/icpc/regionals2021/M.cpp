#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    int tot = 0;
    int rem = n - k;
    
    while (k--) {
        int x;
        cin >> x;
        tot += x;
    }
    
    double worst = (tot - rem * 3) / (double)n;
    double best = (tot + rem * 3) / (double)n;
    cout << worst << ' ' << best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}