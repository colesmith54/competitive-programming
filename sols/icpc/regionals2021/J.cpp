#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    vector<char> v(200, 0);
    for (char c : s) if (v[c]++) {
        cout << "0";
        return;
    }
    cout << "1";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}