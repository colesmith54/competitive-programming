#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> res;
    
    for (int i = 0; i < n; ++i) {
        int low = 0;
        int high = res.size() - 1;
        int pos = res.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (res[mid].back() < a[i]) {
                pos = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (pos >= res.size()) {
            res.push_back({a[i]});
        } else {
            res[pos].push_back(a[i]);
        }
    }

    for (const auto& v : res) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}