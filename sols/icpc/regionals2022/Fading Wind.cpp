#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dist = 0;

    int h, k, v, s;
    cin >> h >> k >> v >> s;

    while (h > 0) {
        v += s;
        v -= max(1, v / 10);
        if (v >= k) ++h;
        if (0 < v && v < k && --h == 0) v = 0;
        if (v <= 0) { h = 0; v = 0; }
        dist += v;
        if (s > 0) --s;
    }

    cout << dist << endl;
}