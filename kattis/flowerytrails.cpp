#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvii = vector<vii>;

const int INF = 1e9;

vi dijkstra(int start, vvii &adj, int p) {
    vi dist(p, INF);
    priority_queue<ii, vector<ii>, std::greater<ii>> pq;
    pq.emplace(0, start);
    dist[start] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (const auto& [v, w] : adj[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, t;
    cin >> p >> t;

    vvii adj(p, vii());
    vector<tuple<int, int, int>> edges;
    edges.reserve(t);

    int p1, p2, l;
    for (int i = 0; i < t; i++) {
        cin >> p1 >> p2 >> l;
        adj[p1].emplace_back(p2, l);
        adj[p2].emplace_back(p1, l);
        edges.emplace_back(p1, p2, l);
    }

    vi dist0 = dijkstra(0, adj, p);
    vi dist1 = dijkstra(p-1, adj, p);

    int shortest_dist = dist0[p-1];
    long long total = 0;

    for (const auto& [u, v, w] : edges) {
        if ((dist0[u] + w + dist1[v] == shortest_dist) ||
            (dist0[v] + w + dist1[u] == shortest_dist)) {
            total += w;
        }
    }

    cout << 2 * total;
}
