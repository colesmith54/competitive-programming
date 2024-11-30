// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

void solve(int n, int m, int q, int s) {
    int u, v, t0, p, d;
    vector<vvi> adj(n, vvi());

    for (int i = 0; i < m; i++) {
       cin >> u >> v >> t0 >> p >> d;
       adj[u].push_back({v, d, t0, p});
    }

    priority_queue<ii, vii, greater<ii>> pq;
    vector<bool> visited(n, false);
    vi dist(n, INT_MAX);

    pq.emplace(0, s);
    dist[s] = 0;

    while (!pq.empty()) {
        auto [time, node] = pq.top(); pq.pop();
        if (visited[node]) continue;
        visited[node] = true;

        for (const vi& edge: adj[node]) {
            v = edge[0], d = edge[1], t0 = edge[2], p = edge[3];

            int t, new_time;
            if (p == 0) {
                if (time > t0) continue;
                t = 0;
            } else {
                t = max(0, (int)ceil((time - t0) / (double)p));
            }

            new_time = (t0 + t * p) + d;
            if (new_time < dist[v]) {
                dist[v] = new_time;
                pq.emplace(new_time, v);
            }
        }
    }

    int dest;
    while (q--) {
        cin >> dest;
        if (dist[dest] == INT_MAX) cout << "Impossible\n";
        else cout << dist[dest] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q, s;
    while (cin >> n >> m >> q >> s) {
        if (!n && !m && !q && !s) break;
        solve(n, m, q, s);
    }
}