#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    vector<int> b(k);
    for (auto& x : b) cin >> x;
    
    vector<ll> pref;
    ll sum = 0;
    
    for (int num : a) {
        sum += num;
        pref.push_back(sum);
    }
    
    set<ll> prefs(pref.begin(), pref.end());
    set<ll> valid;
    
    for (int i = 0; i < n; ++i) {
        ll cand = b[0] - pref[i];
        bool good = true;
        
        for (int j = 0; j < k; ++j) {
            if (!prefs.contains(b[j] - cand)) {
                good = false;
                break;
            }
        }
        
        if (good) {
            valid.insert(cand);
        }
    }
    
    cout << valid.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}