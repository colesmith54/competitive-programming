#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    priority_queue<int> pq;
    
    int x;
    ll ans = 0;
    
    while (n--) {
        cin >> x;
        
        if (x) {
            pq.push(x);
        } else if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}