#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<int> orig(a.begin(), a.end());
    
    int reset = -1;
    vector<int> update(n + 1, -1);
    
    int b, c;
    for (int i = 0; i < m; ++i) {
        cin >> b >> c;
        
        if (update[b] < reset) {
            a[b] = orig[b];
        }
        
        a[b] += c;
        if (a[b] > h) {
            reset = i;
            a[b] = orig[b];
        }
        
        update[b] = i;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (update[i] < reset) {
            a[i] = orig[i];
        }
        
        cout << a[i] << ' ';
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