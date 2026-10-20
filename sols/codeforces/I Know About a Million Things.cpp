#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    int sum = accumulate(a.begin(), a.end(), 0);
    int odds = count_if(a.begin(), a.end(), [sum](int x) { return x % 2 == 1; });
    
    if (a.size() == 2 && odds == 1) {
        cout << "Larpity\n";
        return;
    }
    
    if (a.size() == 3 && odds == 3) {
        cout << "Larpity\n";
        return;
    } 
    
    cout << "Moggity\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}