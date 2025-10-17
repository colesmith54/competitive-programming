#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, g, b;
    cin >> r >> g >> b;

    int hasR, hasG, hasB;
    cin >> hasR >> hasG >> hasB;

    int spRG, spGB;
    cin >> spRG >> spGB;

    int neededR = max(r - hasR, 0);
    int neededG = max(g - hasG, 0);
    int neededB = max(b - hasB, 0);

    spRG -= neededR;
    spGB -= neededB;

    if (spRG >= 0 && spGB >= 0 && spRG + spGB >= neededG) {
        cout << neededR + neededG + neededB;
    } else {
        cout << "-1";
    }
}