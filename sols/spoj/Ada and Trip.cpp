// Cole Smith (colesmith54)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

constexpr int lim = 11;

vector<int> small_dijkstra(vvii& adj, int src) {
    vector<vector<int>> qs(lim);
    vector<int> dist(adj.size(), -1);

    dist[src] = 0;
    qs[0].push_back(src);

    int max_d = 0;
    for (int d = 0; d <= max_d; ++d) {
        auto &q = qs[d % lim];

        while (!q.empty()) {
            int u = q.back(); q.pop_back();
            if (dist[u] != d) continue;

            for (auto &[v, w] : adj[u]) {
                if (dist[v] != -1 && dist[v] <= d + w) continue;
                dist[v] = d + w;
                qs[(d + w) % lim].push_back(v);
                max_d = max(max_d, d + w);
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vvii adj(n);

    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        adj[a].emplace_back(b, l);
        adj[b].emplace_back(a, l);
    }

    while (q--) {
        int qi;
        cin >> qi;

        auto dist = small_dijkstra(adj, qi);

        int maxDist = -1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] == -1) continue;
            if (dist[i] > maxDist) {
                maxDist = dist[i];
                count = 1;
            } else if (dist[i] == maxDist) {
                count++;
            }
        }

        cout << maxDist << ' ' << count << '\n';
    }

    return 0;
}
