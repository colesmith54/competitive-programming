#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s, t, u;
    cin >> s;
    
    vector<int> freq(256, 0);
    
    set<char> later;
    later.insert(CHAR_MAX);
    
    for (char c : s) {
        ++freq[c];
        later.insert(c);
    }
    
    for (char c : s) {
        t.push_back(c);
        
        if (!--freq[c]) {
            later.erase(c);
        }
        
        while (!t.empty() && t.back() <= *later.begin()) {
            u.push_back(t.back());
            t.pop_back();
        }
    }
    
    while (!t.empty()) {
        u.push_back(t.back());
        t.pop_back();
    }
    
    cout << u << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}