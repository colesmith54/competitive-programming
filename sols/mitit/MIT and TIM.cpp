#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<string> cand;
    string curr;

    for (char c : s) {
        if (c != 'I' && (curr.empty() || curr.back() == 'I')) {
            curr += c;
        }
        else if (c == 'I' && (!curr.empty() && curr.back() != 'I')) {
            curr += c;
        }
        else {
            cand.push_back(curr);
            curr = c;
        }
    }

    cand.push_back(curr);
    int ans = 0;

    for (string& p : cand) {
        int m = 0;
        int t = 0;

        for (char c : p) {
            if (c == 'M') ++m;
            else if (c == 'T') ++t;
        }

        ans += min(m, t/2);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}