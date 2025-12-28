#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    
    string curr;
    for (auto& s : a) {
        curr = min(s + curr, curr + s);
    }
    
    cout << curr << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}