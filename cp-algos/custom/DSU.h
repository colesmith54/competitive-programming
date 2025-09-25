#pragma once

#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) {
        parent.assign(n, 0);
        rank.assign(n, 1);

        // set every node to be its own parent
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find_set(int v) {
        // if v is a representative...
        if (parent[v] == v)
            return v;

        // path compression
        parent[v] = find_set(parent[v]);

        return parent[v];
    }

    void union_set(int a, int b) {
        int rep_a = find_set(a);
        int rep_b = find_set(b);

        // don't merge if both nodes are in the same set
        if (rep_a == rep_b)
            return;

        // ensure that rep_a is the larger tree
        if (rank[rep_b] > rank[rep_a])
            swap(rep_a, rep_b);

        // if both trees have equal depths, the new tree will have +1 depth
        if (rank[rep_a] == rank[rep_b])
            ++rank[rep_a];

        parent[rep_b] = rep_a;
    }
};

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<Edge> MST;

sort(edges.begin(), edges.end());

for (Edge e : edges) {
if (find_set(e.u) != find_set(e.v)) {
cost += e.weight;
result.push_back(e);
union_sets(e.u, e.v);
}
}