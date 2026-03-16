#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    deque<int> d;
    int x;
    
    while (n--) {
        cin >> x;
        if (d.empty() || x < d.front()) {
            d.push_front(x);
        } else {
            d.push_back(x);
        }
    }
    
    while (!d.empty()) {
        cout << d.front() << ' ';
        d.pop_front();
    }
    
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}