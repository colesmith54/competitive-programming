/*
*J. Special Problem

time limit per test: 1 second

memory limit per test: 256 megabytes

In the past April Fools contests, the final problem was usually a problem that is special in some way (mysterious languages, problem hidden in a video, etc.).

This year, it is no exception. In fact, this problem is so special that it cannot be displayed as a normal Codeforces problem. You are viewing the special statement now. Please visit this page to submit your solution.

As a reminder, using AI is not allowed in this contest.

Input
The input contains a question or prompt in a single line.

Output
If the question is "Are you a verified human?", output "Yes, I can attest to my status as a thoroughly validated, carbon-based biological entity." (without quotes).

Otherwise, any output is accepted.

Example
Input
Do you think this contest should be rated?
Output
Yes
Input
Are you a verified human?
Output
Yes, I can attest to my status as a thoroughly validated, carbon-based biological entity.
Notes
If you want to really make sure you are a human, you can click this link to restart verification.
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    getline(cin, s);
    
    if (s == "Are you a verified human?") {
        cout << "Yes, I can attest to my status as a thoroughly validated, carbon-based biological entity." << endl;
    } else {
        cout << "Yes";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}