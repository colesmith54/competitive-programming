#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<string> g(n);
    for (auto& x : g) cin >> x;
    
    constexpr int d[5] = {-1, 0, 1, 0, -1};
    vector<vector<char>> seen(n, vector<char>(m, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] != 'B') continue;
            
            for (int k = 0; k < 4; ++k) {
                int ni = i + d[k];
                int nj = j + d[k + 1];
                
                if (ni < 0 || nj < 0 || ni == n || nj == m) continue;
                
                if (g[ni][nj] == 'G') goto nah;
                if (g[ni][nj] == '.') g[ni][nj] = '#';
            }
        }
    }
    
    if (g.back().back() != '#') {
        queue<pair<int, int>> q;
        q.emplace(n - 1, m - 1);
        seen[n - 1][m - 1] = true;
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int k = 0; k < 4; ++k) {
                int nx = x + d[k];
                int ny = y + d[k + 1];
                
                if (nx < 0 || ny < 0 || nx == n || ny == m || seen[nx][ny] || g[nx][ny] == '#') continue;
                
                seen[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'G' && !seen[i][j]) goto nah;
            if (g[i][j] == 'B' && seen[i][j]) goto nah;
        }
    }
    
    cout << "Yes\n";
    return;
    
nah:
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}