#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    vector<int> runs;
    int curr = 1;
    
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            ++curr;
        } else {
            runs.push_back(curr);
            curr = 1;
        }
    }
    
    runs.push_back(curr);
    
    int ans = runs.size();
    
    if (s[0] != s.back()) {
        for (int run : runs) {
            if (run > 1) {
                ++ans;
                break;
            }
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
