// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, d;
    cin >> n >> d;
    
    vector<int> ans;
    ans.push_back(1);

    if (n >= 3) ans.push_back(3);
    else if (n == 2 && d % 3 == 0) ans.push_back(3);

    if (d == 5) ans.push_back(5);

    if (n >= 3) ans.push_back(7);
    else if (n == 2 && d == 7) ans.push_back(7);

    if (n >= 6) ans.push_back(9);
    else if (n >= 3 && d % 3 == 0) ans.push_back(9);
    else if (n == 2 && d == 9) ans.push_back(9);

    for (auto& x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}