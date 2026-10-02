#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    multiset<ll> a;
    while (n--) {
        int x;
        cin >> x;
        a.insert(x);
    }
    
    int ans = 0;
    int limit = 1e6;
    
    while (limit-- && a.size() > 1) {
        ll v = *a.begin();
        a.erase(a.begin());
        
        if (*a.begin() == v) {
            a.erase(a.begin());
        } else {
            ++ans;
        }
        
        a.insert(2 * v);
    }
    
    if (ans > 9e5) ans = -1;
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}