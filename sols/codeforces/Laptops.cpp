#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<pair<int, int>> price;
    priority_queue<pair<int, int>> quality;

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        price.emplace(a, i);
        quality.emplace(b, i);
    }

    while (n--) {
        auto currP = price.top(); price.pop();
        auto currQ = quality.top(); quality.pop();

        if (currP.second != currQ.second) {
            cout << "Happy Alex";
            return 0;
        }
    }

    cout << "Poor Alex";
}