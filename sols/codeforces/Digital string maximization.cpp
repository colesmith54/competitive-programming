// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();

    for (int i = 0; i < n - 1; i++) {
        int best = s[i];
        int next = i;

        for (int j = i; j <= i + 9 && j < n; j++) {
            if (s[j] - (j - i) > best) {
                best = s[j] - (j - i);
                next = j;
            }
        }

        for (int j = next; j > i; j--) {
            swap(s[j - 1], s[j]);
        }

        s[i] -= (next - i);
    }

    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}