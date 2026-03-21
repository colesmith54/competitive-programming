#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    for (int i = 2; i < 2 * n; i += 2) {
        cout << "? " << i + 1 << ' ' << i + 2 << endl;
        
        int res;
        cin >> res;
        
        if (res == 1) {
            cout << "! " << i + 1 << endl;
            return;
        }
    }
    
    cout << "? 1 3" << endl;
    int res1; cin >> res1;
    
    cout << "? 1 4" << endl;
    int res2; cin >> res2;
    
    if (res1 | res2) cout << "! 1" << endl;
    else cout << "! 2" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}