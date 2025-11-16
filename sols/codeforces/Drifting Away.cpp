#include <bits/stdc++.h>

using namespace std;


void solve() {
    string s;
    cin >> s;

    // infinite cycle if input is not in form: <<<...*>>>...

    int n = (int) s.size();
    int i = 0;

    int l = 0;
    int r = 0;

    while (i < n && s[i] == '<') {
        ++i;
        ++l;
    }

    if (i < n && s[i] == '*') {
        ++i;
        ++l;
        ++r;
    }

    while (i < n && s[i] == '>') {
        ++i;
        ++r;
    }

    cout << ((i == n) ? max(l, r) : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}