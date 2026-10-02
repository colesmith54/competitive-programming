#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<int> d(n);
    for (auto& x : d) cin >> x;
    
    int l = 0;
    int r = n - 1;
    ll ls = 0, rs = 0, sum1 = 0;
    
    while (l <= r) {
        if (ls < rs) {
            ls += d[l++];
        } else {
            rs += d[r--];
        }
        
        if (ls == rs) {
            sum1 = ls;
        }
    }
    
    cout << sum1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}