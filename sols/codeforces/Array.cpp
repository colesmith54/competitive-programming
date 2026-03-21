#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    for (int i = 0; i < n; ++i) {
        int l = 0;
        int g = 0;
        
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[i]) ++g;
            else if (a[j] < a[i]) ++l;
        }
        
        cout << max(l, g) << ' ';
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