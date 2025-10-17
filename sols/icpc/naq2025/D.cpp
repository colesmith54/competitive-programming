#include <bits/stdc++.h>

using namespace std;

// 0 = north
// 1 = east
// 2 = south
// 3 = west

int mask(int r, int c, int dir) {
    return r + (c << 6) + (dir << 12);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dir = 1;

    int r, c;
    cin >> r >> c;

    int i, j;
    cin >> i >> j;

    int ei, ej;
    cin >> ei >> ej;

    --i; --j; --ei; --ej;

    vector<vector<char>> g(r, vector<char>(c));
    for (auto& p : g) {
        for (auto& q : p) {
            cin >> q;
            q -= '0';
        }
    }

    int m = mask(i, j, 1);
    bitset<50000> bs;

    auto can_left = [&]() {
        if (dir == 0 && j > 0 && !g[i][j-1]) return true;
        if (dir == 1 && i > 0 && !g[i-1][j]) return true;
        if (dir == 2 && j < c-1 && !g[i][j+1]) return true;
        if (dir == 3 && i < r-1 && !g[i+1][j]) return true;
        return false;
    };

    auto can_forward = [&]() {
        if (dir == 0 && i > 0 && !g[i-1][j]) return true;
        if (dir == 1 && j < c-1 && !g[i][j+1]) return true;
        if (dir == 2 && i < r-1 && !g[i+1][j]) return true;
        if (dir == 3 && j > 0 && !g[i][j-1]) return true;
        return false;
    };

    auto move_forward = [&]() {
        if (dir == 0) --i;
        if (dir == 1) ++j;
        if (dir == 2) ++i;
        if (dir == 3) --j;
    };

    auto left_dir = [&]() {
        return (dir + 3) % 4;
    };

    auto right_dir = [&]() {
        return (dir + 1) % 4;
    };

    while ((i != ei || j != ej) && !bs.test(m)) {
        bs.set(m);

        if (can_left()) {
            dir = left_dir();
            move_forward();
        } else if (can_forward()) {
            move_forward();
        } else {
            dir = right_dir();
        }

        m = mask(i, j, dir);
    }

    cout << ((i == ei && j == ej) ? "1" : "0");
}