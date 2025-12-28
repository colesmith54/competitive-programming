#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l, a, b;
    cin >> l >> a >> b;
    
    set<int> s;
    while (s.insert(a).second) {
        a = (a + b) % l;
    }
    
    cout << *s.rbegin() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}