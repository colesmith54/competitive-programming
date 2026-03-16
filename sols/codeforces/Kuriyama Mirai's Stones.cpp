#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<int> stones(n);
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }
 
    vector<int> sortedStones = stones;
    sort(sortedStones.begin(), sortedStones.end());
 
    vector<ll> prefix(n+1);
    vector<ll> sortedPrefix(n+1);
 
    prefix[0] = 0;
    sortedPrefix[0] = 0;
 
    for (int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + stones[i];
        sortedPrefix[i+1] = sortedPrefix[i] + sortedStones[i];
    }
 
    int m;
    cin >> m;
 
    int type, l, r;
    while (m--) {
        cin >> type >> l >> r;
        if (type == 1) {
            cout << (prefix[r] - prefix[l-1]) << "\n";
        } else {
            cout << (sortedPrefix[r] - sortedPrefix[l-1]) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}