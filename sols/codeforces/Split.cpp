#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(2 * n);
    for (auto& x : a) cin >> x;

    vector<int> freq(2 * n + 1, 0);
    for (auto x : a) ++freq[x];

    // an even divisible by 4 can be split into two odds (n/2) \pm 1
    // an even not divisible by 4 can be split into two odds (n/2)
    // an odd is fine, makes one odd
    // but an odd can also be used to fill the \pm 1 gap from even4

    int odd = 0, even = 0, even4 = 0;
    for (int f : freq) {
        if (f == 0) continue;
        if (f % 2 == 0 && f % 4 == 0) ++even4;
        else if (f % 2 == 0) ++even;
        else ++odd;
    }

    if (odd == 0 && even4 % 2) {
        cout << odd + 2 * even + 2 * even4 - 2 << '\n';
    } else {
        cout << odd + 2 * even + 2 * even4 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}