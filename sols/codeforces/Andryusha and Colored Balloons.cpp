// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int k = 0;
    for (int i = 1; i <= n; i++) {
        k = max(k, (int)g[i].size() + 1);
    }

    stack<int> stk;
    vector<int> color(n + 1, -1);
    vector<int> parent(n + 1, -1);

    stk.push(1);
    color[1] = 1;
    parent[1] = 1;

    while (!stk.empty()) {
        int u = stk.top(); stk.pop();
        int assign_color = (color[u] % k) + 1;
        for (int v : g[u]) {
            if (color[v] != -1) continue;
            parent[v] = u;

            if (assign_color == color[parent[u]]) {
                assign_color = (assign_color % k) + 1;
            }

            color[v] = assign_color;
            assign_color = (assign_color % k) + 1;
            stk.push(v);
        }
    }

    cout << k << '\n';
    for (int i = 1; i <= n; i++) {
        cout << color[i] << ' ';
    }
}