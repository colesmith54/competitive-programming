// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int x;
    cin >> x;

    while (x % 33 != 0) {
        string s = to_string(x);
        int digits = (int)s.size();

        int i = 0;
        while (i < digits - 1 && !(s[i] == '3' && s[i+1] == '3')) i++;
        if (i == digits - 1) {
            cout << "NO\n";
            return;
        }

        string temp = s;
        s = s.substr(0, i);
        if (i < digits - 2) s += temp.substr(i + 2);
        if (s.empty()) break;

        while (!s.empty() && s[0] == '0') s = s.substr(1);
        x = stoi(s);
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}