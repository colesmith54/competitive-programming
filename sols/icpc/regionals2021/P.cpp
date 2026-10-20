#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    long long tot = 0;
    map<int, int> read;
    
    for (int i = 1; i <= m; ++i) {
        int s;
        cin >> s;
        
        tot += n;
        tot -= (i - read[s]);
        read[s] = i;
        
        cout << tot << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}