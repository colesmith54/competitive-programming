// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    char curr;
    vector<bool> top(n);
    vector<int> bottom(n);
    for (int i = 0; i < n; i++) { cin >> curr; top[i] = (curr == '.'); }
    for (int i = 0; i < n; i++) { cin >> curr; bottom[i] = (curr == '.'); }

    bool multiple = false;

    for (int i = 0; i < n; i++) {
        if (!top[i] && !bottom[i]) continue;
        if (top[i] && bottom[i]) {
            top[i] = bottom[i] = false;
            if (i < n-1 && top[i+1] && bottom[i+1]) {
                multiple = true;
            }
        } else {
            if (top[i]) {
                if (i == n-1 || !top[i+1]) {
                    cout << "None\n"; return;
                }
                top[i] = top[i+1] = false;
            } else {
                if (i == n-1 || !bottom[i+1]) {
                    cout << "None\n"; return;
                }
                bottom[i] = bottom[i+1] = false;
            }
        }
    }

    cout << (multiple ? "Multiple\n" : "Unique\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}