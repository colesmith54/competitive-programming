#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    int win_cost = a[p - 1];
    a[p - 1] = 0;
    
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < k; ++i) {
        pq.push(a[i]);
    }
    
    queue<int> q;
    for (int i = k; i < n; ++i) {
        q.push(a[i]);
    }
    
    int sum = 0;
    int ans = 0;
    
    while (true) {
        int card = pq.top();
        pq.pop();
        
        int cost = card != 0 ? card : win_cost;
        if (sum + cost > m) {
            break;
        }
        
        sum += cost;
        if (!card) ++ans;
        
        if (q.empty()) {
            pq.push(card);
        } else {
            q.push(card);
            pq.push(q.front());
            q.pop();
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