#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int exp = 1;
    int ptr = 0;
    
    while (ptr < s.size()) {
        int length = to_string(exp).size();
        if (s.substr(ptr, length) != to_string(exp)) {
            cout << exp;
            return;
        }
        ptr += length;
        ++exp;
    }
    
    cout << exp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}