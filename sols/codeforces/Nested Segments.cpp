#include <bits/stdc++.h>
using namespace std;

struct node {
    int l, r, idx;
};

vector<int> t;

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;

    if (l == tl && r == tr) {
        return t[v];
    }

    int tm = (tl + tr) / 2;

    return query(v * 2, tl, tm, l, min(r, tm)) +
           query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] += new_val;
        return;
    }

    int tm = (tl + tr) / 2;

    if (pos <= tm) {
        update(v * 2, tl, tm, pos, new_val);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos, new_val);
    }

    t[v] = t[v * 2] + t[v * 2 + 1];
}

void solve() {
    int n;
    cin >> n;

    vector<node> seg(n);
    vector<int> r;

    for (int i = 0; i < n; i++) {
        cin >> seg[i].l >> seg[i].r;
        seg[i].idx = i;
        r.push_back(seg[i].r);
    }

    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());

    sort(seg.begin(), seg.end(), [](const node& a, const node& b) {
        if (a.l != b.l) return a.l < b.l;
        return a.r > b.r;
    });

    t.assign(4 * n, 0);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        int pos = lower_bound(r.begin(), r.end(), seg[i].r) - r.begin();
        ans[seg[i].idx] = query(1, 0, n - 1, 0, pos - 1);
        update(1, 0, n - 1, pos, 1);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}