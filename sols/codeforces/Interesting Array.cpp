#include <bits/stdc++.h>

using namespace std;

struct query {
    int l, r, q;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<query> queries(m);
    vector<int> a(n + 1, 0);

    for (int i = 0; i < m; i++) {
        cin >> queries[i].l >> queries[i].r >> queries[i].q;
    }

    for (int b = 0; b < 30; ++b) {
        vector<int> diff(n + 2, 0);

        for (auto &qr : queries) {
            if (qr.q & (1 << b)) {
                ++diff[qr.l];
                --diff[qr.r + 1];
            }
        }

        int cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += diff[i];
            if (cur > 0) {
                a[i] |= (1 << b);
            }
        }
    }

    int LOG = 20;
    vector<vector<int>> st(LOG, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        st[0][i] = a[i];
    }

    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            st[k][i] = st[k - 1][i] & st[k - 1][i + (1 << (k - 1))];
        }
    }

    auto rq = [&](int l, int r) {
        int len = r - l + 1;
        int k = __lg(len);
        return st[k][l] & st[k][r - (1 << k) + 1];
    };

    for (auto &qr : queries) {
        if (rq(qr.l, qr.r) != qr.q) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}