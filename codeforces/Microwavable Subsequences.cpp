// Cole Smith (colesmith54)
#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

class FenwickTree {
private:
    vll ft;
public:
    FenwickTree(int m) { ft.assign(m+1, 0); }

    ll rsq(int j) const {
        ll sum = 0;
        for (; j > 0; j -= LSOne(j)) sum += ft[j];
        return sum;
    }

    ll rsq(int i, int j) const {
        if (i > j) return 0;
        return rsq(j) - rsq(i-1);
    }

    void update(int i, ll v) {
        for (; i < ft.size(); i += LSOne(i)) ft[i] += v;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    set<int> distinct;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        distinct.insert(a[i]);
    }

    ll c = distinct.size();
    ll ans = 1LL * c * (m - c);

    FenwickTree ft(n);
    map<int, int> last;

    for (int i = 1; i <= n; i++) {
        int y = a[i];
        if (last.count(y)) {
            int l = last[y];
            ans += ft.rsq(l + 1, i - 1);
            ft.update(l, -1);
        }
        ft.update(i, 1);
        last[y] = i;
    }

    ans += c * (c - 1);
    cout << ans;
}
