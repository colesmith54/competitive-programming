#include <bits/stdc++.h>

using namespace std;

struct Node {
    int sz = 1;
    vector<Node*> children;
    vector<int> cost;
};

void solve() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    Node head = Node();
    stack<Node*> stk;
    stk.push(&head);
    
    for (char c : s) {
        if (c == '(') {
            Node* v = new Node();
            stk.top()->children.push_back(v);
            stk.push(v);
        } else {
            stk.pop();
        }
    }
    
    function<void(Node*)> dfs = [&](Node* u) {
        int pre = 0;
        for (Node* v : u->children) {
            dfs(v);

            u->cost.push_back(pre);
            pre += v->sz;
            u->sz += v->sz;
        }
    };
    
    dfs(&head);
    
    int ans = 0;
    vector<int> path;
    
    function<void(Node*, int)> dfs2 = [&](Node* u, int cost) {
        if (u != &head) {
            path.push_back(cost);
            int d = path.size();
            
            int start = lower_bound(path.begin(), path.end(), cost - k) - path.begin();
            ans = max(ans, d - start);
            
            if (cost <= k) {
                ans = max(ans, min(n / 2, d + k));
            }
        }
        
        for (int i = 0; i < u->children.size(); ++i) {
            dfs2(u->children[i], cost + u->cost[i]);
        }
        
        if (u != &head) {
            path.pop_back();
        }
    };
    
    dfs2(&head, 0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}