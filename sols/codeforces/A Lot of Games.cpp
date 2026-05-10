#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    TrieNode* children[26]{};
    bool win = false;
    bool lose = false;
};

struct Trie {
    TrieNode root;
    
    void dfs(TrieNode* curr) {
        bool leaf = true;
        
        for (auto child : curr->children) {
            if (!child) continue;
            leaf = false;
            
            dfs(child);
            
            if (!child->win) curr->win = true;
            if (!child->lose) curr->lose = true;
        }
        
        if (leaf) {
            curr->win = false;
            curr->lose = true;
        }
    }
    
    void insert(const string& s) {
        TrieNode* curr = &root;
        for (char c : s) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    
    Trie t;
    
    while (n--) {
        string s;
        cin >> s;
        t.insert(s);
    }
    
    t.dfs(&t.root);
    if (!t.root.win) cout << "Second\n";
    else if (t.root.lose) cout << "First\n";
    else if (k % 2) cout << "First\n";
    else cout << "Second\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}