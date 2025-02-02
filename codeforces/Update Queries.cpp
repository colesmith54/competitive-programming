// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;

    vector<int> idx(m);
    for (auto& x : idx) cin >> x;

    string c;
    cin >> c;

    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
    sort(c.begin(), c.end());

    for (int i = 0; i < idx.size(); ++i) {
        s[idx[i] - 1] = c[i];
    }

    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}