// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;


void solve() {
    int n, r, start, end;
    cin >> n >> r >> start >> end;
    start--; end--;

    vvii adj(n);

    while (r--) {
        int u, v, t;
        cin >> u >> v >> t;
        u--; v--;

        adj[u].emplace_back(v, t + 12);
        adj[v].emplace_back(u, t + 12);
    }

    priority_queue<pll, vector<pll>, greater<>> pq;
    pq.emplace(0, start);

    vector<ll> dist(n, LLONG_MAX);
    dist[start] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (u == end) break;
        for (auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[u] + w, v);
            }
        }
    }

    cout << dist[end] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    while (k--) solve();
}