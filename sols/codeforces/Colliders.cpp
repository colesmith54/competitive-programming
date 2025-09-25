// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> p;
bitset<10000001> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i <= 1e5; i++) {
        if (!bs[i]) continue;
        for (ll j = (ll)i*i; j <= 1e5; j += i)
            bs[j] = 0;
        p.push_back(i);
    }
}

vector<int> factorize(int n) {
    vector<int> factorization;
    for (int d : p) {
        if (d * d > n) break;
        if (n % d == 0) factorization.push_back(d);
        while (n % d == 0) n /= d;
    }
    if (n > 1) factorization.push_back(n);
    return factorization;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();

    int n, m;
    cin >> n >> m;

    vector<int> on(1e5 + 1, 0);

    while (m--) {
        char sign;
        cin >> sign;

        bool turn_on = (sign == '+');

        int x;
        cin >> x;

        auto factors = factorize(x);
        factors.push_back(x);

        if (turn_on) {
            int conflict = -1;
            for (int factor: factors) {
                if (on[factor]) {
                    conflict = on[factor];
                    break;
                }
            }

            if (conflict != -1) {
                if (conflict == x) cout << "Already on\n";
                else cout << "Conflict with " << conflict << '\n';
            } else {
                cout << "Success\n";
                for (int factor: factors) on[factor] = x;
            }
        } else {
            if (on[x] != x) {
                cout << "Already off\n";
                continue;
            }

            for (int factor : factors) {
                on[factor] = 0;
            }
            cout << "Success\n";
        }
    }
}