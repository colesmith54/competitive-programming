// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n;
    cin >> n;

    ll sumA = 0, lenA = 0;
    ll sumB = 0, lenB = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (i % 2) { sumB += x; lenB++; }
        else { sumA += x; lenA++; }
    }

    if (sumA % lenA == 0 && sumB % lenB == 0 && sumA/lenA == sumB/lenB) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}