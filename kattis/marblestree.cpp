// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

ll dfs(int node, const vector<vi>& children, const vi& marbles, ll& ans) {
    ll surplus = marbles[node] - 1;
    for (auto child : children[node]) {
        ll child_surplus = dfs(child, children, marbles, ans);
        ans += abs(child_surplus);
        surplus += child_surplus;
    }
    return surplus;
}

void solve(int n) {
    int v, m, d, c;
    vi marbles(n+1, 0);
    vector<vi> children(n+1, vi());
    vector<bool> isChild(n+1, false);

    for (int i = 0; i < n; i++) {
        cin >> v >> m >> d;
        marbles[v] = m;

        for (int j = 0; j < d; j++) {
            cin >> c;
            children[v].push_back(c);
            isChild[c] = true;
        }
    }

    ll ans = 0;
    int root = -1;

    for (int i = 1; i <= n; i++) {
        if (!isChild[i]){
            root = i;
            break;
        }
    }

    dfs(root, children, marbles, ans);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && (n != 0)) {
        solve(n);
    }
}