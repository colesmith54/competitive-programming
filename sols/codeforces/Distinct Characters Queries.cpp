#include <bits/stdc++.h>

using namespace std;

int t[4000005];

int make_data(char c) {
    return (1 << (c - 'a'));
}

int combine(int l, int r) {
    return l | r;
}

void build(char a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_data(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, char val) {
    if (tl == tr) {
        t[v] = make_data(val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, val);
        else
            update(v*2+1, tm+1, tr, pos, val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) 
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve() {
    string s;
    cin >> s;
    
    int n = s.size();
    build(s.data(), 1, 0, n - 1);
    
    int q;
    cin >> q;
    
    while (q--) {
        int t;
        cin >> t;
        
        if (t == 1) {
            int pos; cin >> pos;
            char c; cin >> c;
            
            update(1, 0, n - 1, --pos, c);
        } else {
            int l, r;
            cin >> l >> r;
            
            int ans = query(1, 0, n - 1, --l, --r);
            cout << __builtin_popcount(ans) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}