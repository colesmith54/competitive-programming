// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string before, after;
    cin >> before >> after;

    int m = min(before.size(), after.size());

    int l = 0;
    while (l < m && before[l] == after[l]) l++;

    int r1 = before.size() - 1;
    int r2 = after.size() - 1;

    while (r1 >= l && r2 >= l && before[r1] == after[r2]) {
        r1--;
        r2--;
    }

    int k = after.size() - 1 - r2;
    k = min(k, (int)(before.size()) - l);

    int inserted_length = after.size() - l - k;
    inserted_length = max(inserted_length, 0);

    cout << inserted_length;
}