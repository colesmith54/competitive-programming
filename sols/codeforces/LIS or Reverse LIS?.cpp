// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> freq;
    for(auto &x : a) {
        cin >> x;
        ++freq[x];
    }

    int lis1 = 0;
    int lis2 = 0;
    bool common = true;
    for (auto& [num, count] : freq) {
        if (count > 1) {
            ++lis1;
            ++lis2;
        } else if (common) {
            ++lis1;
            ++lis2;
            common = false;
        } else {
            (lis1 < lis2) ? ++lis1 : ++lis2;
        }
    }

    cout << min(lis1, lis2) << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}
