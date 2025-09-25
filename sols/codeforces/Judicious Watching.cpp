// Cole Smith (colesmith54)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Task {
    ll start;
    ll end;
    ll total_free;
    Task(ll s, ll e, ll t) : start(s), end(e), total_free(t) {}
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<ll, ll>> tasks(n);
    for (auto& x : tasks) cin >> x.first;
    for (auto& x : tasks) cin >> x.second;

    sort(tasks.begin(), tasks.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return (a.second == b.second) ? (a.first < b.first) : (a.second < b.second);
    });

    vector<Task> task_times;
    ll prev_start = LLONG_MAX;
    for (int i = n - 1; i >= 0; i--) {
        auto& [duration, deadline] = tasks[i];
        ll end_time = min(prev_start, deadline);
        ll start_time = end_time - duration;
        prev_start = start_time;
        task_times.emplace_back(start_time, end_time, 0);
    }

    sort(task_times.begin(), task_times.end(), [](const Task& a, const Task& b) {
        return a.start < b.start;
    });

    vector<ll> start_times;
    start_times.reserve(task_times.size());
    for (const auto& task : task_times) {
        start_times.push_back(task.start);
    }

    ll total = 0;
    ll prev_end = 0;
    for (auto & task_time : task_times) {
        ll gap = task_time.start - prev_end;
        total += gap;
        task_time.total_free = total;
        prev_end = task_time.end;
    }

    vector<ll> episodes_prefix(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> episodes_prefix[i];
        episodes_prefix[i] += episodes_prefix[i-1];
    }

    while (q--) {
        ll t;
        cin >> t;

        ll idx = upper_bound(start_times.begin(), start_times.end(), t) - start_times.begin() - 1;

        ll total_free;
        if (idx < 0) {
            total_free = t;
        } else {
            Task& task = task_times[idx];
            total_free = task.total_free;
            if (t > task.end) total_free += (t - task.end);
        }

        auto ep = upper_bound(episodes_prefix.begin(), episodes_prefix.end(), total_free);
        ll ans = distance(episodes_prefix.begin(), --ep);

        cout << ans << ' ';
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
}
