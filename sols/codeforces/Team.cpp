// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int z, o;
    cin >> z >> o;

    if (z - 1 > o) {
        cout << -1;
        return 0;
    }

    // must start with a zero
    if (z - 1 == o) {
        string ans = "0";
        while (o--) ans += "10";

        cout << ans;
        return 0;
    }

    // otherwise start with a one
    string ans;
    while (o >= 2 && z >= 1 && o > z) {
        ans += "110";
        o -= 2; z--;
    }

    while (z-- && o--) {
        ans += "10";
    }

    if (o > 2) {
        cout << -1;
        return 0;
    }

    ans += string(o, '1');
    cout << ans;
}