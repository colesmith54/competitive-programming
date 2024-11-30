// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, s, k;
    cin >> r >> s >> k;

    vector<string> pic(r);
    for (int i = 0; i < r; i++) {
        cin >> pic[i];
    }

    int ans = 0;
    int row = -1, col = -1;

    vvi pre(r + 1, vi(s + 1, 0));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++) {
            pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j];
            if (pic[i][j] == '*') pre[i+1][j+1]++;
        }
    }

    for (int i = k-1; i < r; i++) {
        for (int j = k-1; j < s; j++) {
            int x1 = i - k + 1, y1 = j - k + 1;
            int x2 = i, y2 = j;

            int inner_x1 = x1 + 1, inner_y1 = y1 + 1;
            int inner_x2 = x2 - 1, inner_y2 = y2 - 1;

            int current = pre[inner_x2+1][inner_y2+1] - pre[inner_x1][inner_y2+1] - pre[inner_x2+1][inner_y1] + pre[inner_x1][inner_y1];

            if (current > ans) {
                ans = current;
                row = x1;
                col = y1;
            }
        }
    }

    cout << ans << '\n';

    pic[row][col] = '+';
    pic[row+k-1][col] = '+';
    pic[row][col+k-1] = '+';
    pic[row+k-1][col+k-1] = '+';

    for (int i = row+1; i < row+k-1; i++) {
        pic[i][col] = '|';
        pic[i][col+k-1] = '|';
    }
    for (int j = col+1; j < col+k-1; j++) {
        pic[row][j] = '-';
        pic[row+k-1][j] = '-';
    }

    for (int i = 0; i < r; i++) {
        cout << pic[i] << '\n';
    }
}