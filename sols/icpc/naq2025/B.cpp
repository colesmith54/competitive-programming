//
// Created by anthony on 10/11/25.
//
//
// Created by anthony on 7/18/24.
//

#include <bits/stdc++.h>
#define MOD 1000000007
#define all(x) x.begin(),x.end())

using namespace std;
typedef long long ll;

template <typename S, typename T>
struct PH {
    size_t operator() (const pair<S,T>& p) const {
        return hash<S>()(p.first) ^ hash<T>()(p.second);
    }
};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename K, typename V>
using umap_safe = unordered_map<K, V, custom_hash>;

template <typename K>
using uset_safe = unordered_set<K, custom_hash>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int r, c, n;
    cin >> r >> c >> n;
    vector<pair<int,int>> towers(n);
    for (int i = 0; i < n; i++) {
        cin >> towers[i].first >> towers[i].second;
        --towers[i].first;
        --towers[i].second;
    }

    vector<vector<int>> first_closest(r, vector<int>(c, -1)), second_closest(r, vector<int>(c, -1)), seen(r, vector<int>(c, 0));

    struct node {
        int r;
        int c;
        // tower
        int t;
        node(int r_, int c_, int t_) : r(r_), c(c_), t(t_) {}
    };

    queue<node> f;
    for (int i = 0; i < n; ++i) {
        f.emplace(towers[i].first, towers[i].second, i + 1);
    }

    auto get = [&] (node& node_, vector<vector<int>>& grid) {
        return grid[node_.r][node_.c];
    };

    auto set_node = [&] (node& node_, vector<vector<int>>& grid) {
        grid[node_.r][node_.c] = node_.t;
    };

    auto valid  = [&] (int x, int y) {
        return (x >= 0 && x < r && y >= 0 && y < c);
    };

    auto explore = [&] (const node& cur) {
        int &a = first_closest[cur.r][cur.c];
        int &b = second_closest[cur.r][cur.c];

        if (a == -1) {
            a = cur.t;
        } else if (b == -1 && cur.t != a) {
            b = cur.t;
        }
    };

    for (int i = 0; i < n; ++i) {
        explore(node(towers[i].first, towers[i].second, i + 1));
    }

    while (!f.empty()) {
        auto cur = f.front();
        f.pop();

        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};
        for (int i = 0; i < 4; ++i) {
            node new_node(cur.r + dx[i], cur.c + dy[i], cur.t);
            if (valid(new_node.r, new_node.c)) {
                if (((get(new_node, first_closest) == -1) ||
                     (get(new_node, second_closest) == -1)) &&
                    ((get(new_node, first_closest) != cur.t) &&
                     (get(new_node, second_closest) != cur.t))){
                    f.push(new_node);
                }

                explore(new_node);
            }
        }
    }

    for (auto& row : first_closest) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    for (auto& row : second_closest) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }

}