// Cole Smith (colesmith54)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> p;
bitset<1000001> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i*i <= 1e6; i++) {
        if (!bs[i]) continue;
        for (int j = i*i; j <= 1e6; j += i) bs[j] = 0;
        p.push_back(i);
    }
}

unordered_map<int, int> factorize(int n) {
    unordered_map<int, int> factorization;
    for (int d : p) {
        if (d * d > n) break;
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n > 1) factorization[n]++;
    return factorization;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();

    int n;
    cin >> n;

    auto factors = factorize(n);
    int max_exp = 0;

    int ans = 1;
    for (auto& [factor, exp] : factors) {
        ans *= factor;
        max_exp = max(max_exp, exp);
    }

    if (n == 1 || max_exp == 1) {
        cout << n << ' ' << 0;
        return 0;
    }

    int ops = ceil(log2(max_exp));

    if (pow(ans, pow(2,ops)) != n) ops++;

    cout << ans << ' ' << ops;
}