// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vvi adj(n + 1);
    int a, b;

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto bfs = [&](const int start) -> ii {
        queue<int> q;
        q.push(start);

        int farthest = start;
        int maxd = 0;

        vector<int> dist(n + 1, -1);
        dist[start] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    if (dist[v] > maxd) {
                        maxd = dist[v];
                        farthest = v;
                    }
                }
            }
        }

        return { farthest, maxd };
    };

    auto [start, dist] = bfs(1);
    auto [end, diam] = bfs(start);
    cout << diam << '\n';
}