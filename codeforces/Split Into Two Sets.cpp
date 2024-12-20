// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class DSU {
private:
    vector<int> p, rank, set_size;
    int num_sets;
public:
    DSU(int n) {
        p.assign(n, 0);
        for (int i = 0; i < n; ++i) p[i] = i;
        rank.assign(n, 0);
        set_size.assign(n, 1);
        num_sets = n;
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    int numDisjointSets() const { return num_sets; }
    int sizeOfSet(int i) { return set_size[findSet(i)]; }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        else if (rank[x] == rank[y]) ++rank[y];
        p[x] = y;
        set_size[y] += set_size[x];
        --num_sets;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<int> freq(n + 1, 0);
    DSU d(n + 1);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        d.unionSet(a, b);
        freq[a]++; freq[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (freq[i] != 2 || d.sizeOfSet(i) % 2 == 1) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}