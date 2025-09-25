#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<char> a(n);
    for (auto& x : a)
        cin >> x;

    int mask = 0;

    for (char c : a)
        mask |= (1 << (tolower(c) - 'a'));

    cout << ((mask == (1 << 26) - 1) ? "YES" : "NO");
}