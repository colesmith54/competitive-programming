#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int lim = sqrt(1e7);
    vector<char> is_prime(lim + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i <= lim; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= lim; j += i) {
                is_prime[j] = false;
            }   
        }
    }
    
    vector<int> primes;
    for (int i = 2; i <= lim; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    vector<int> cs(n);
    for (auto& x : cs) cin >> x;
    
    map<int, int> pt;
    vector<pair<int, int>> ans;
    
    for (int c : cs) {
        int x = c;
        vector<int> div = {1};

        for (int p : primes) {
            if (p * p > x) break;

            int exp = 0;
            while (x % p == 0) {
                ++exp;
                x /= p;
            }

            int curr = 1;
            int sz = div.size();

            for (int e = 1; e <= exp; ++e) {
                curr *= p;
                for (int k = 0; k < sz; ++k) {
                    div.push_back(curr * div[k]);
                }
            }
        }

        if (x > 1) {
            int sz = div.size();
            for (int k = 0; k < sz; ++k) {
                div.push_back(x * div[k]);
            }
        }

        int& idx = pt[c];
        if (idx >= div.size()) {
            cout << "NO\n";
            return;
        }

        int a = div[idx++];
        ans.emplace_back(a, c / a);
    }
    
    cout << "YES\n";
    for (auto& [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}