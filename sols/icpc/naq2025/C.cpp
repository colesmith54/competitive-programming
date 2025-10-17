#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    set<int> s;
    int x;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        s.insert(x);
    }

    cout << min((int)s.size(), k);
}