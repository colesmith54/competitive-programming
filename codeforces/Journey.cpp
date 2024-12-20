// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<double> prob(n+1);
    vector<int> d(n+1);

    d[1] = 0;
    prob[1] = 1.0;

    vector<bool> visited(n+1, false);
    vector<int> leaves;

    function<void(int)> dfs = [&](int curr) {
        int next_cities = 0;
        for (auto& next : adj[curr]) {
            if (visited[next]) continue;
            next_cities++;

            visited[next] = true;
            int parent_branches = adj[curr].size() - 1;
            if (curr == 1) parent_branches++;

            prob[next] = prob[curr] * (1.0 / parent_branches);
            d[next] = d[curr] + 1;

            dfs(next);
        }

        // end of journey at this city
        if (next_cities == 0) {
            leaves.push_back(curr);
        }
    };

    visited[1] = true;
    dfs(1);

    double ans = 0;
    for (int city : leaves) {
        ans += (d[city] * prob[city]);
    }

    cout << fixed << setprecision(15) << ans;
}