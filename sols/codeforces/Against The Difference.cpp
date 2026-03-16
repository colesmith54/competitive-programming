#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200000 + 10;

int T;
int n;
int a[MAXN];
int dp[MAXN];
deque<int> q[MAXN];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        // clear deques
        for (int i = 1; i <= n; i++) {
            q[i].clear();
        }

        // read array
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 1; i <= n; i++) {
            // carry previous best
            dp[i] = dp[i - 1];

            // add index to deque for this value
            q[a[i]].push_back(i);

            // keep only the last a[i] occurrences
            if (q[a[i]].size() > a[i]) {
                q[a[i]].pop_front();
            }

            // if we have exactly a[i] occurrences
            if (q[a[i]].size() == a[i]) {
                int start = q[a[i]].front();
                dp[i] = max(dp[i], dp[start - 1] + a[i]);
            }
        }

        printf("%d\n", dp[n]);
    }

    return 0;
}