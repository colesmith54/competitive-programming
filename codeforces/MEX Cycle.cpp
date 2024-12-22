// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;

    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        g[i].push_back((i == 0) ? n-1 : i - 1);
        g[i].push_back((i == n-1) ? 0 : i + 1);
    }

    if (abs(x - y) != 1 && abs(x - y) != n-1) {
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> a(n, -1);
    a[x] = 0;
    a[y] = 1;

    queue<int> q;
    q.push(x);
    q.push(y);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (a[v] != -1) continue;
            vector<int> neighbors;
            for (int w : g[v]) if (a[w] != -1) {
                neighbors.push_back(a[w]);
            }

            bool seen[8] = {false};
            for (int label : neighbors) {
                seen[label] = true;
            }

            int mex = 0;
            while (seen[mex]) mex++;
            a[v] = mex;
            q.push(v);
        }
    }

    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}