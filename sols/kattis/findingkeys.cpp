// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

vi buildLCP(const string& s, const vi& idx) {
    int n = (int) s.size();
    vi rank(n), lcp(n - 1);
    for (int i = 0; i < n; i++) {
        rank[idx[i]] = i;
    }

    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (rank[i] > 0) {
            int j = idx[rank[i] - 1];
            while (k < n && s[(i + k) % n] == s[(j + k) % n]) k++;

            lcp[rank[i] - 1] = k;
            if (k) k--;
        }
    }

    return lcp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vi key(n);
    for (int& k : key)
        cin >> k;

    string ref(n, '0');
    for (int i = 0; i < n; i++) {
        ref[i] = (key[i] < key[(i + 1) % n]) ? '0' : '1';
    }

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);

    vector<int> rank(n), tmp(n);
    for (int i = 0; i < n; i++) {
        rank[i] = ref[i] - '0';
    }

    for (int k = 1; k < n; k <<= 1) {
        auto cmp = [&](int a, int b) {
            if (rank[a] != rank[b]) return rank[a] < rank[b];
            return rank[(a + k) % n] < rank[(b + k) % n];
        };

        sort(idx.begin(), idx.end(), cmp);

        tmp[idx[0]] = 0;
        for (int i = 1; i < n; ++i) {
            tmp[idx[i]] = tmp[idx[i - 1]] + cmp(idx[i - 1], idx[i]);
        }

        rank = tmp;
        if (rank[idx[n - 1]] == n - 1) break;
    }

    vi lcp = buildLCP(ref, idx);
    vi ans(n, 0);

    for (int i = 0; i < n; ++i) {
        int pos = rank[i];
        int& k = ans[i];

        if (pos > 0) k = max(k, lcp[pos - 1] + 1);
        if (pos < n - 1) k = max(k, lcp[pos] + 1);
    }

    if (*max_element(ans.begin(), ans.end()) > n) {
        ans.assign(n, -1);
    }

    for (int k : ans) cout << k << '\n';
    return 0;
}