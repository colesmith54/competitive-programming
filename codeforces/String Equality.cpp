// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;

    string a, b;
    cin >> a >> b;

    vector<int> freq_a(26, 0);
    vector<int> freq_b(26, 0);
    for (char c : a) ++freq_a[c - 'a'];
    for (char c : b) ++freq_b[c - 'a'];

    int available_groups = 0;
    for (int i = 0; i < 26; i++) {
        int have = freq_a[i];
        int need = freq_b[i];

        int diff = have - need;
        if (diff == 0) continue;

        if (diff % k != 0) {
            cout << "No\n";
            return;
        }

        int groups = abs(diff) / k;
        if (have > need) {
            available_groups += groups;
        } else {
            available_groups -= groups;
            if (available_groups < 0) {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}