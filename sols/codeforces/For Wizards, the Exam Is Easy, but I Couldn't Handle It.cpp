#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int bd = 0;
    int bl = 1;
    int br = 1;

    for (int l = 0; l < n; ++l) {
        int gr = 0;
        int le = 0;

        for (int r = l + 1; r < n; ++r) {
            if (a[r] > a[l]) ++gr;
            else if (a[r] < a[l]) ++le;

            if (gr - le < bd) {
                bd = gr - le;
                bl = l + 1;
                br = r + 1;
            }
        }
    }

    cout << bl << ' ' << br << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}