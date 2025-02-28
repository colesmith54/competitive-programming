#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        vector<ll> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (a[i] > 0 ? a[i] : 0);
        }

        vector<ll> suffix(n + 1, 0);
        for (int i = n-1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + (a[i] < 0 ? -a[i] : 0);
        }

        ll ans = 0;
        for (int k = 0; k <= n; k++) {
            ans = max(ans, prefix[k] + suffix[k]);
        }

        cout << ans << "\n";
    }
    return 0;
}
