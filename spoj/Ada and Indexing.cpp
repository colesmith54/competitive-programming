// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

struct Node {
    Node* children[26];
    int count = 0;
};

struct Trie {
    Node* head;
    Trie() : head(new Node()) {};

    void insert(string& word) {
        Node* curr = head;
        for (const char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = new Node();
            curr = curr->children[idx];
            curr->count++;
        }
    }

    int prefixCount(string& prefix) {
        Node* curr = head;
        for (const char c : prefix) {
            curr = curr->children[c - 'a'];
            if (!curr) return 0;
        }
        return curr->count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    Trie t;
    string curr;

    while (n--) {
        cin >> curr;
        t.insert(curr);
    }

    while (q--) {
        cin >> curr;
        cout << t.prefixCount(curr) << '\n';
    }
}