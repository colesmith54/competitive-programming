#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string s, t;
    cin >> s >> t;
    
    int a = 0;
    int b = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        if (s.substr(i, 2) == "()") ++a;
        if (t.substr(i, 2) == "()") ++b;
    }
    
    if (a != b) {
        cout << "NO\n";
        return;
    }
    
    int d1 = 0;
    int d2 = 0;
    
    {
        stack<int> p;
        vector<int> l;
    
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') p.push(i);
            else { l.push_back(p.top()); p.pop(); }
        }
        
        while (!l.empty() && l.back() == d1) {
            ++d1;
            l.pop_back();
        }
    }
    
    {
        stack<int> p;
        vector<int> l;
    
        for (int i = 0; i < n; ++i) {
            if (t[i] == '(') p.push(i);
            else { l.push_back(p.top()); p.pop(); }
        }
        
        while (!l.empty() && l.back() == d2) {
            ++d2;
            l.pop_back();
        }
    }
    
    cout << (d1 == d2 ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
