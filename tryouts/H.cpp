#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class SegmentTree {
    int n;
    vector<int> A, lazy;
    vector<array<int, 20>> st;

    int l(int p) { return p << 1; }
    int r(int p) { return (p << 1) + 1; }

    void conquer(int p) {
        for (int b = 0; b < 20; ++b) {
            st[p][b] = st[l(p)][b] + st[r(p)][b];
        }
    }

    void build(int p, int L, int R) {
        if (L == R) {
            for (int b = 0; b < 20; ++b) {
                st[p][b] = (A[L] >> b) & 1;
            }
        } else {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            conquer(p);
        }
    }

    void propagate(int p, int L, int R) {
        if (lazy[p] == 0) return;

        for (int b = 0; b < 20; ++b) {
            if ((lazy[p] >> b) & 1) {
                st[p][b] = R - L + 1 - st[p][b];
            }
        }

        if (L != R) {
            lazy[l(p)] ^= lazy[p];
            lazy[r(p)] ^= lazy[p];
        }

        lazy[p] = 0;
    }

    ll rsq(int p, int L, int R, int i, int j) {
        propagate(p, L, R);
        if (i > j) return 0;

        if (L >= i && R <= j) {
            ll ans = 0;
            for (int b = 0; b < 20; ++b) {
                ans += (1LL << b) * st[p][b];
            }
            return ans;
        }

        int m = (L + R) / 2;
        return rsq(l(p), L, m, i, min(m, j))
             + rsq(r(p), m + 1, R, max(i, m + 1), j);
    }

    void update(int p, int L, int R, int i, int j, int val) {
        propagate(p, L, R);
        if (i > j) return;

        if (L >= i && R <= j) {
            lazy[p] ^= val;
            propagate(p, L, R);
        } else {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
            conquer(p);
        }
    }

public:
    SegmentTree(const vector<int>& a)
        : n(a.size()), A(a), lazy(4 * n, 0), st(4 * n) {
        build(1, 0, n - 1);
    }

    void update(int i, int j, int val) {
        update(1, 0, n - 1, i, j, val);
    }

    ll rsq(int i, int j) {
        return rsq(1, 0, n - 1, i, j);
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    SegmentTree st(a);

    int q;
    cin >> q;

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        --l; --r;

        if (t == 1) {
            cout << st.rsq(l, r) << '\n';
        } else {
            int x;
            cin >> x;
            st.update(l, r, x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}