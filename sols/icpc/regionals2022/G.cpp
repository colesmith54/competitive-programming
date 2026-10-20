#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> f(11, 1);
    for (int i = 2; i <= 10; ++i) {
        f[i] = (f[i - 1] * i) % 10;
    }
    
    while (n--) {
        int x;
        cin >> x;
        
        cout << f[x] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}