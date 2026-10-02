#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define LSOne(S) ((S) & -(S))

class FenwickTree {
    vll ft;
public:
    FenwickTree(int m) { ft.assign(m+1, 0); }
    void build (const vll &f) {
        int m = (int)f.size()-1;
        ft.assign(m+1, 0);
        for (int i = 1; i <= m; ++i) {
            ft[i] += f[i];
            if (i+LSOne(i) <= m) ft[i+LSOne(i)] += ft[i];
        }
    }

    FenwickTree(const vll &f) { build(f); }
    FenwickTree(int m, const vi &s) {
        vll f(m+1, 0);
        for (int i = 0; i < (int)s.size(); ++i)
            ++f[s[i]];
        build(f);
    }

    ll rsq(int j) const {
        ll sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }
    ll rsq(int i, int j) const { return rsq(j) - rsq(i-1); }

    void update(int i, ll v) {
        for (; i < (int)ft.size(); i += LSOne(i))
            ft[i] += v;
    }
    int select(ll k) {
        int lo = 1, hi = ft.size()-1;
        for (int i = 0; i < 30; ++i) {
            int mid = (lo + hi) / 2;
            (rsq(1, mid) < k) ? lo = mid : hi = mid;
        }
        return hi;
    }
};

void solve() {
    int n;
    cin >> n;
    
    FenwickTree ft(1e3);
    vector<int> ans(1e6, 0);
    
    for (int i = 0; i < 1e3; ++i) {
        for (int j = 0; j < 1e3; ++j) {
            int l = abs(
                ((i % 10) + (i / 10 % 10) + (i / 100)) -
                ((j % 10) + (j / 10 % 10) + (j / 100))
            );
            
            ans[i * 1e3 + j] = ft.rsq(l);
            ft.update(l + 1, 1);
        }
    }
    
    while (n--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}