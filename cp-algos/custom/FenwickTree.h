#pragma once

#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

class FenwickTree {
private:
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

class RUPQ {
private:
    FenwickTree ft;
public:
    RUPQ(int m) : ft(FenwickTree(m)) {}
    void range_update(int ui, int uj, int v) {
        ft.update(ui, v);
        ft.update(uj+1, -v);
    }
    ll point_query(int i) { return ft.rsq(i); }
};

class RURQ {
private:
    RUPQ rupq;
    FenwickTree purq;
public:
    RURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {}
    void range_update(int ui, int uj, int v) {
        rupq.range_update(ui, uj, v);
        purq.update(ui, v * (ui-1));
        purq.update(uj+1, -v*uj);
    }
    ll rsq(int j) { return j * rupq.point_query(j) - purq.rsq(j); }
    ll rsq(int i, int j) { return rsq(j) - rsq(i-1); }
};