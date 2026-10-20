#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    int n = s.size();
    vector<vector<int>> freq(10, vector<int>(10, 0));
    
    for (int i = 1; i < n; ++i) {
        int a = s[i - 1] - '0';
        int b = s[i] - '0';
        ++freq[a][b];
        ++freq[b][a];
    }
    
    int ans = 1e9;
    vector<int> v(9);
    iota(v.begin(), v.end(), 1);
    
    do {
        vector<int> pos(10);
        for (int i = 0; i < 9; ++i) {
            pos[v[i]] = i;
        }
        
        int cost = pos[s[0] - '0'];
        
        for (int i = 0; i <= 9; ++i) {
            for (int j = i + 1; j <= 9; ++j) {
                cost += abs(pos[j] - pos[i]) * freq[i][j];
            }
        }
        
        ans = min(ans, cost);
    } while (next_permutation(v.begin(), v.end()));
    
    cout << ans + n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}