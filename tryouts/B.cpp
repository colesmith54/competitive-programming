#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string out;
    bool done = false;
    
    while (n--) {
        string s;
        cin >> s;
        
        if (!done && s.substr(0, 2) == "OO") {
            s.replace(0, 2, "++");
            done = true;
        }
        
        if (!done && s.substr(3, 2) == "OO") {
            s.replace(3, 2, "++");
            done = true;
        }
        
        out += s + "\n";
    }
    
    if (done) {
        cout << "YES\n" << out;
    } else {
        cout << "NO";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}