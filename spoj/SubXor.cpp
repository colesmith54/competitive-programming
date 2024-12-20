// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

struct Trie {
    struct Node {
        int count = 0;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    Node* head;

    Trie() : head(new Node()) {}

    void insert(unsigned int val) {
        Node* curr = head;
        for (int i = 31; i >= 0; i--) {
            if ((val >> i) & 1) {
                if (!curr->right) curr->right = new Node();
                curr->right->count++;
                curr = curr->right;
            } else {
                if (!curr->left) curr->left = new Node();
                curr->left->count++;
                curr = curr->left;
            }
        }
    }

    int countXORLessThan(int k, int curr_xor) {
        int ans = 0;
        Node* curr = head;

        for (int i = 31; i >= 0; i--) {
            if (!curr) break;

            bool k_bit = (k >> i) & 1;
            bool xor_bit = (curr_xor >> i) & 1;

            if (k_bit) {
                if (!xor_bit && curr->left) ans += curr->left->count;
                if (xor_bit && curr->right) ans += curr->right->count;
                curr = xor_bit ? curr->left : curr->right;
            } else {
                curr = xor_bit ? curr->right : curr->left;
            }
        }

        return ans;
    }
};

void solve() {
    unsigned int n, k;
    cin >> n >> k;

    vi a(n);
    for (int& x : a) cin >> x;

    int curr_xor = 0;
    ll ans = 0;

    Trie trie;
    trie.insert(0);

    for (int i = 0; i < n; i++) {
        curr_xor ^= a[i];
        ans += trie.countXORLessThan(k, curr_xor);
        trie.insert(curr_xor);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}