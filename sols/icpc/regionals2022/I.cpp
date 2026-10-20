#include <bits/stdc++.h>

using namespace std;

using Die = array<int, 6>;

Die spin(const Die& d) {
    return {d[0], d[1], d[4], d[5], d[3], d[2]};
}

string check(Die d) {
    array<Die, 6> possible = {{
        {d[0], d[1], d[2], d[3], d[4], d[5]},
        {d[1], d[0], d[3], d[2], d[4], d[5]},
        {d[2], d[3], d[1], d[0], d[4], d[5]},
        {d[3], d[2], d[0], d[1], d[4], d[5]},
        {d[4], d[5], d[2], d[3], d[1], d[0]},
        {d[5], d[4], d[2], d[3], d[0], d[1]}
    }};

    string best = "999999";
    for (Die die : possible) {
        for (int i = 0; i < 4; ++i) {
            string curr;
            for (auto& x : die) curr += to_string(x);
            best = min(best, curr);
            die = spin(die);
        }
    }
    
    return best;
}

void solve() {
    int n;
    cin >> n;
    
    vector<Die> d(n);
    for (auto& x : d) {
        for (auto& y : x) cin >> y;
    }
    
    map<string, int> se;
    
    for (Die die : d) {
        ++se[check(die)];
    }
    
    int best = 0;
    for (auto& [k, v] : se) {
        if (v > best) best = v;
    }
    
    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}