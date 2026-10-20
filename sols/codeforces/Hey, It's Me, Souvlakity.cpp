#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    set<int> so, ka;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            so.insert(i + 1);
        } else {
            ka.insert(i + 1);
        }
    }
    
    if (so.size() == 1) {
        cout << "0\n";
        return;
    }
    
    if (so.size() == 2) {
        cout << "1\n";
        return;
    }
    
    cout << *so.rbegin() - *so.begin() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}