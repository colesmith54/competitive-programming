#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> g(26, 0);
    string curr;
    cin >> curr;
    
    string ans;
    queue<int> q;
    
    while (--n) {
        string prev = curr;
        cin >> curr;
        
        int i = 0;
        int sz = min(prev.size(), curr.size());
        while (i < sz && prev[i] == curr[i]) ++i;
        
        if (i == sz) {
            if (prev.size() > curr.size()) {
                goto done;
            }
            continue;
        }
        
        g[curr[i] - 'a'] |= 1 << (prev[i] - 'a');
    }
    
    for (int i = 0; i < 26; ++i) {
        if (!g[i]) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        ans.push_back(u + 'a');
        
        for (int v = 0; v < 26; ++v) {
            if (g[v] & (1 << u)) { 
                g[v] &= ~(1 << u);
                if (!g[v]) q.push(v);
            }
        }
    }
    
done:
    
    cout << (ans.size() == 26 ? ans : "Impossible") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}