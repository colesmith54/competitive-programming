#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<char> stk;
    int ops = 0;

    for (char c : s) {
        if (!stk.empty() && c == stk.top()) {
            stk.pop(); ops++;
        } else {
            stk.push(c);
        }
    }

    if (ops % 2 == 0) {
        cout << "No";
    } else {
        cout << "Yes";
    }
}