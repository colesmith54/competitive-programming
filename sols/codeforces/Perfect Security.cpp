#include <bits/stdc++.h>

using namespace std;

struct Trie {
    struct TrieNode {
        int val = 0;
        int has = 0;
        TrieNode* children[2] = {nullptr, nullptr};
    };

    TrieNode head = TrieNode();
public:
    void insert(unsigned int v) {
        TrieNode* curr = &head;
        for (int i = 30; i >= 0; --i) {
            int bit = (v >> i) & 1;
            if (!curr->children[bit]) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
            curr->has++;
            curr->val = v;
        }
    }

    void erase(unsigned int v) {
        TrieNode* curr = &head;
        for (int i = 30; i >= 0; --i) {
            int bit = (v >> i) & 1;
            curr = curr->children[bit];
            if (!curr) break;
            if (curr->has) curr->has--;
        }
    }

    unsigned int findSmallestXOR(int v) {
        TrieNode* curr = &head;
        for (int i = 30; i >= 0; --i) {
            int bit = (v >> i) & 1;
            if (curr->children[bit] && curr->children[bit]->has) {
                curr = curr->children[bit];
            } else if (curr->children[1 - bit] && curr->children[1 - bit]->has) {
                curr = curr->children[1 - bit];
            } else {
                break;
            }
        }

        return curr->val;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    Trie t;
    for (int i = 0; i < n; ++i) {
        unsigned int x; cin >> x;
        t.insert(x);
    }

    vector<int> ans;
    for (int num : a) {
        int p = t.findSmallestXOR(num);
        ans.push_back(num ^ p);
        t.erase(p);
    }

    for (auto& x : ans) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}