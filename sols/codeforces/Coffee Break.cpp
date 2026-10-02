#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    
    vector<int> a(n);
    set<int> s;
    
    for (auto& x : a) {
        cin >> x;
        s.insert(x);
    }
    
    map<int, int> idx;
    int day = 0;
    
    while (!s.empty()) {
        ++day;
        
        auto p = s.begin();
        while (p != s.end()) {
            int curr = *p;
            s.erase(p);
            idx[curr] = day;
            p = s.lower_bound(curr + d + 1);
        }
    }
    
    cout << day << '\n';
    for (int x : a) cout << idx[x] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}