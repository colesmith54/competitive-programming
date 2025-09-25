// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cnt(n + 1, 0);
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ++cnt[a[i]];
    }

    vector<int> need;
    for (int i = 1; i <= n; i++) {
        if (!cnt[i]) {
            need.push_back(i);
        }
    }

    int missing = (int)need.size();

    int pos = 0;
    vector<bool> seen(n + 1, false);

    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] == 1) continue;
        if (need[pos] < a[i] || seen[a[i]]) {
            --cnt[a[i]];
            a[i] = need[pos++];
        }
        seen[a[i]] = true;
        if (pos >= missing) break;
    }

    cout << missing << '\n';
    for (auto& x : a) cout << x << ' ';
}