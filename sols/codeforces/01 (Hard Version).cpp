#include <bits/stdc++.h>

using namespace std;

struct node {
    int pairs, open, close;
};

node t[4000005];

node make_data(char c) {
    return node(0, c == '0', c == '1');
}

node combine(node l, node r) {
    int a = l.pairs + r.pairs + min(l.open, r.close);
    int b = l.open + r.open - min(l.open, r.close);
    int c = l.close + r.close - min(l.open, r.close);
    return node(a, b, c);
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

node query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return node(0, 0, 0);
    if (l == tl && r == tr) 
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve() {
    string s;
    cin >> s;
    
    build(s.data(), 1, 0, s.size() - 1);
    int n = s.size();
    
    int q;
    cin >> q;
    
    while (q--) {
        int k;
        cin >> k;
        
        if (k == 1) {
            int x;
            cin >> x;
            
            char next = s[--x] == '0' ? '1' : '0';
            update(1, 0, n - 1, x, next);
            s[x] = next;
        } else {
            int l, r;
            cin >> l >> r;
            
            node ans = query(1, 0, n - 1, --l, --r);
            cout << ans.open + ans.close << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}