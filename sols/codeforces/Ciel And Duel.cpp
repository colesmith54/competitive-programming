#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <numeric>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> aa;
    vector<int> dd;
    
    for (int i = 0; i < n; ++i) {
        string s;
        int x;
        cin >> s >> x;
        if (s == "ATK") {
            aa.push_back(x);
        } else {
            dd.push_back(x);
        }
    }

    multiset<int> s;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }

    int res = 0;

    priority_queue<int> atk(aa.begin(), aa.end());
    priority_queue<int> def(dd.begin(), dd.end());
    multiset<int> st = s;
    int curr = 0;
    bool can_clear_all = true;

    while (!def.empty()) {
        int d = def.top();
        auto it = st.upper_bound(d);
        if (it == st.end()) {
            can_clear_all = false;
            break;
        }
        st.erase(it);
        def.pop();
    }

    if (can_clear_all) {
        while (!atk.empty()) {
            int a = atk.top();
            auto it = st.lower_bound(a);
            if (it == st.end()) {
                can_clear_all = false;
                break;
            }
            curr += *it - a;
            st.erase(it);
            atk.pop();
        }
    }

    if (can_clear_all) {
        curr += accumulate(st.begin(), st.end(), 0);
        res = max(res, curr);
    }

    priority_queue<int, vector<int>, greater<int>> low(aa.begin(), aa.end());
    priority_queue<int> avail;
    for (int x : s) {
        avail.push(x);
    }

    curr = 0;
    while (!low.empty() && !avail.empty()) {
        int a = low.top();
        int b = avail.top();
        if (a >= b) {
            break;
        }
        curr += b - a;
        low.pop();
        avail.pop();
    }

    res = max(res, curr);

    cout << res << '\n';

    return 0;
}