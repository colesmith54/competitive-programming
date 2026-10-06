#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y);}
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y);}
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    T dist2() const { return x * x + y * y; }
    T cross(P p) const { return x * p.y - y * p.x; }
};

typedef Point<ll> P;

array<P, 2> hullDiameter(vector<P> S, int& count) {
    int n = size(S), j = n < 2 ? 0 : 1;
    pair<ll, array<P, 2>> res({0, {S[0], S[1]}});
    set<pair<int, int>> cuts;
    
    for (int i = 0; i < j; ++i) {
        for (;; j = (j + 1) % n) {
            ll d = (S[i] - S[j]).dist2();
            if (d > res.first) cuts.clear();
        
            res = max(res, {d, {S[i], S[j]}});
            if (d == res.first && i != j && (i + 1) % n != j && (j + 1) % n != i) {
                cuts.insert({min(i, j), max(i, j)});
            }
            
            if ((S[(j + 1) % n] - S[j]).cross(S[i + 1] - S[i]) >= 0) {
                break;
            }
        }
    }
    
    count = cuts.size();
    return res.second;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    
    vector<P> pts(n);
    for (auto& p : pts) {
        cin >> p.x >> p.y;
    }

    int cnt = 0;
    auto [a, b] = hullDiameter(pts, cnt);
    
    ll d2 = (a - b).dist2();
    long double best = sqrtl(d2);
    ll ans = llroundl(k / (2 * best));
    
    __int128 tot = (__int128)4 * ans * ans * d2;
    __int128 t = (__int128)k * k;
    
    if (tot < t || (tot == t && ans > cnt)) {
        ++ans;
    }
    
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}