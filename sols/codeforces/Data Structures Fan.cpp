// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

class SegmentTree {
private:
    struct Node {
        int xor0, xor1;
    };

    int n;
    vector<int> A;
    string S;
    vector<Node> st;
    vector<bool> flip;

    int l(int p) { return p << 1; }
    int r(int p) { return (p << 1) + 1; }

    void build(int p, int L, int R) {
        if (L == R) {
            if (S[L] == '0') {
                st[p].xor0 = A[L];
                st[p].xor1 = 0;
            } else {
                st[p].xor0 = 0;
                st[p].xor1 = A[L];
            }
        } else {
            int M = (L + R) / 2;
            build(l(p), L, M);
            build(r(p), M+1, R);
            st[p].xor0 = st[l(p)].xor0 ^ st[r(p)].xor0;
            st[p].xor1 = st[l(p)].xor1 ^ st[r(p)].xor1;
        }
    }

    void propagate(int p, int L, int R) {
        if (flip[p]) {
            int tmp = st[p].xor0;
            st[p].xor0 = st[p].xor1;
            st[p].xor1 = tmp;

            if (L != R) {
                flip[l(p)] = !flip[l(p)];
                flip[r(p)] = !flip[r(p)];
            }
            flip[p] = false;
        }
    }

    void update(int p, int L, int R, int i, int j) {
        propagate(p, L, R);
        if (j < L || R < i) return;
        if (i <= L && R <= j) {
            flip[p] = true;
            propagate(p, L, R);
            return;
        }

        int M = (L + R) / 2;
        update(l(p), L, M, i, j);
        update(r(p), M+1, R, i, j);

        st[p].xor0 = st[l(p)].xor0 ^ st[r(p)].xor0;
        st[p].xor1 = st[l(p)].xor1 ^ st[r(p)].xor1;
    }

    Node query(int p, int L, int R, int i, int j) {
        Node ret = {0, 0};
        if (j < L || R < i) return ret;

        propagate(p, L, R);
        if (i <= L && R <= j) return st[p];

        int M = (L + R) / 2;
        Node leftRes = query(l(p), L, M, i, j);
        Node rightRes = query(r(p), M+1, R, i, j);
        ret.xor0 = leftRes.xor0 ^ rightRes.xor0;
        ret.xor1 = leftRes.xor1 ^ rightRes.xor1;
        return ret;
    }

public:
    SegmentTree(const vector<int> &initialA, const string &initialS) {
        A = initialA;
        S = initialS;
        n = (int)A.size();
        st.assign(4*n, {0,0});
        flip.assign(4*n, false);
        build(1, 0, n-1);
    }

    void update(int i, int j) {
        update(1, 0, n-1, i, j);
    }

    int query(int i, int j, char g) {
        Node res = query(1, 0, n-1, i, j);
        return (g == '0') ? res.xor0 : res.xor1;
    }
};


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    string s;
    cin >> s;

    int q;
    cin >> q;

    SegmentTree st(a, s);

    while (q--) {
        int tp;
        cin >> tp;

        if (tp == 1) {
            int l, r;
            cin >> l >> r;
            st.update(l - 1, r - 1);
        } else {
            char g;
            cin >> g;
            cout << st.query(0, n-1, g) << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}