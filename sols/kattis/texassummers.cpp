// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

double weight(const ii& a, const ii& b) {
    double dx = abs(a.first - b.first);
    double dy = abs(a.second - b.second);

    return pow(dx, 2.0) + pow(dy, 2.0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 0) {
        cout << '-';
        return 0;
    }

    vii nodes(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].first >> nodes[i].second;
    }

    cin >> nodes[0].first >> nodes[0].second;
    cin >> nodes[n+1].first >> nodes[n+1].second;

    vvii adj(n + 2, vii());
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (i == j) continue;

            int w = weight(nodes[i], nodes[j]);
            adj[i].emplace_back(j, w);
            adj[j].emplace_back(i, w);
        }
    }

    priority_queue<ii, vii, greater<ii>> pq;
    vi dist(n + 2, INT_MAX);
    vi parent(n + 2, -1);

    pq.emplace(0, 0);
    dist[0] = 0;

    unordered_set<int> visited;

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (!visited.insert(u).second) continue;

        for (const auto& [v, w] : adj[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
                parent[v] = u;
            }

            if (v == n + 1) break;
        }
    }

    if (parent[n+1] == 0) {
        cout << '-';
        return 0;
    }

    vi path;
    int k = n + 1;
    while (parent[k] != 0) {
        path.push_back(parent[k]);
        k = parent[k];
    }

    reverse(path.begin(), path.end());

    for (const int p : path) {
        cout << p-1 << '\n';
    }
}