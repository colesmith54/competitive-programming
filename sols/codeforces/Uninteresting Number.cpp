// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    string n;
    cin >> n;

    vector<int> freq(10, 0);
    int total = 0;

    for (char d : n) {
        freq[d - '0']++;
        total += (d - '0');
    }

    int needed = (9 - (total % 9)) % 9;
    if (!needed) {
        cout << "YES\n";
        return;
    }

    while (needed) {
        if (needed % 2 == 0 && needed <= 2 * freq[2]) {
            cout << "YES\n";
            return;
        } else if (freq[3]) {
            total += 6; freq[3]--;
        } else if (freq[2]) {
            total += 2; freq[2]--;
        } else {
            break;
        }

        needed = (9 - (total % 9)) % 9;
    }

    cout << (needed ? "NO\n" : "YES\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}