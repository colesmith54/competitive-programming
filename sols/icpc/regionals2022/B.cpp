#include <bits/stdc++.h>

using namespace std;

void solve() {
    int t;
    cin >> t;
    
    map<string, double> note = {
        {"A", 440.0 * pow(2.0, 0.0/12)},
        {"A#", 440.0 * pow(2.0, 1.0/12)},
        {"Bb", 440.0 * pow(2.0, 1.0/12)},
        {"B", 440.0 * pow(2.0, 2.0/12)},
        {"C", 440.0 * pow(2.0, 3.0/12)},
        {"C#", 440.0 * pow(2.0, 4.0/12)},
        {"Db", 440.0 * pow(2.0, 4.0/12)},
        {"D", 440.0 * pow(2.0, 5.0/12)},
        {"D#", 440.0 * pow(2.0, 6.0/12)},
        {"Eb", 440.0 * pow(2.0, 6.0/12)},
        {"E", 440.0 * pow(2.0, 7.0/12)},
        {"F", 440.0 * pow(2.0, 8.0/12)},
        {"F#", 440.0 * pow(2.0, 9.0/12)},
        {"Gb", 440.0 * pow(2.0, 9.0/12)},
        {"G", 440.0 * pow(2.0, 10.0/12)},
        {"G#", 440.0 * pow(2.0, 11.0/12)},
        {"Ab", 440.0 * pow(2.0, 11.0/12)},
    };
    
    vector<double> f(t);
    for (auto& x : f) cin >> x;
    
    bool gmaj = true;
    bool cmaj = true;
    bool ebmaj = true;
    bool fsharpmin = true;
    bool gmin = true;
    
    auto is = [&note](double d, const string& s) {
        while (d >= 880) d /= 2;
        while (d < 440) d *= 2;
        // cout << d << ' ' << note[s] << ' ' << (bool)(abs(d - note[s]) <= 1e-4) << endl;
        return abs(d - note[s]) <= 1e-4;
    };
    
    map<string, vector<string>> key = {
        {"gmaj", {"G", "A", "B", "C", "D", "E", "F#"}},
        {"cmaj", {"C", "D", "E", "F", "G", "A", "B"}},
        {"ebmaj", {"Eb", "F", "G", "Ab", "Bb", "C", "D"}},
        {"fsharpmin", {"F#", "G#", "A", "B", "C#", "D", "E"}},
        {"gmin", {"G", "A", "Bb", "C", "D", "Eb", "F"}}
    };
    
    for (double d : f) {
        bool good = true;
        
        if (gmaj) {
            good = false;
            for (string& n : key["gmaj"]) {
                if (is(d, n)) {
                    good = true;
                    break;
                }
            }
            if (!good) gmaj = false;
        }
        
        
        if (cmaj) {
            good = false;
            for (string& n : key["cmaj"]) {
                if (is(d, n)) {
                    good = true;
                    break;
                }
            }
            if (!good) cmaj = false;
        }
        
        if (ebmaj) {
            good = false;
            for (string& n : key["ebmaj"]) {
                if (is(d, n)) {
                    good = true;
                    break;
                }
            }
            if (!good) ebmaj = false;
        }
        
        if (fsharpmin) {
            good = false;
            for (string& n : key["fsharpmin"]) {
                if (is(d, n)) {
                    good = true;
                    break;
                }
            }
            if (!good) fsharpmin = false;
        }
        
        if (gmin) {
            good = false;
            for (string& n : key["gmin"]) {
                if (is(d, n)) {
                    good = true;
                    break;
                }
            }
            if (!good) gmin = false;
        }
    }
    
    int num = gmaj + cmaj + ebmaj + fsharpmin + gmin;
    if (num != 1) {
        cout << "cannot determine key";
        return;
    }
    
    if (gmaj) {
        cout << "G major\n";
        for (double d : f) {
            for (string& n : key["gmaj"]) {
                if (is(d, n)) {
                    cout << n << '\n';
                }
            }
        }
    }
    
    if (cmaj) {
        cout << "C major\n";
        for (double d : f) {
            for (string& n : key["cmaj"]) {
                if (is(d, n)) {
                    cout << n << '\n';
                }
            }
        }
    }
    
    if (ebmaj) {
        cout << "Eb major\n";
        for (double d : f) {
            for (string& n : key["ebmaj"]) {
                if (is(d, n)) {
                    cout << n << '\n';
                }
            }
        }
    }
    
    if (fsharpmin) {
        cout << "F# minor\n";
        for (double d : f) {
            for (string& n : key["fsharpmin"]) {
                if (is(d, n)) {
                    cout << n << '\n';
                }
            }
        }
    }
    
    if (gmin) {
        cout << "G minor\n";
        for (double d : f) {
            for (string& n : key["gmin"]) {
                if (is(d, n)) {
                    cout << n << '\n';
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}