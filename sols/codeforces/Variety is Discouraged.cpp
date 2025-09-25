#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    map<int, int> freq;
    for (int x : a) ++freq[x];

    int len = 0;
    int L = -1, R = -1;
    int curr = 0;

    for (int i = 0; i < n; ++i){
        if (freq[a[i]] > 1) {
            int slen = i - curr;
            if (slen > len){
                len = slen;
                L = curr;
                R = i - 1;
            }
            curr = i + 1;
        }
    }

    int slen = n - curr;
    if (slen > len){
        len = slen;
        L = curr;
        R = n - 1;
    }

    if (len > 0) cout << L + 1 << " " << R + 1 << "\n";
    else cout << 0 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}