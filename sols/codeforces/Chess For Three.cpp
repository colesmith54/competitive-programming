#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int a;
    int spec = 3;
    
    while (n--) {
        cin >> a;
        
        if (spec == a) {
            cout << "NO\n";
            return;
        }
        
        spec = 6 - spec - a;
    }
    
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}