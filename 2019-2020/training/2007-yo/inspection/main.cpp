// Test case path: [path]
// https://atcoder.jp/contests/joi2007yo/tasks/joi2007yo_e

#include <bits/stdc++.h>
using namespace std;

struct Condition {
    bool confirmedGood;
    bool confirmedBad;
};

struct Test {
    vector<int> parts;
    int result;
};

int main() {
    int A, B, C, N;
    cin >> A >> B >> C >> N;
    vector<Condition> states = vector<Condition>(A + B + C);
    vector<Test> tests = vector<Test>(N);
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        Test t = Test();
        t.parts = {a, b, c};
        t.result = d;
        tests[i] = t;
    }
    for (auto &test : tests) {
        if (test.result == 1) {
            for (auto &part : test.parts) {
                states[part].confirmedGood = true;
            }
        }
    }
    for (auto &test : tests) {
        if (test.result == 0) {
            int numGood = 0;
            int indexBad = -1;
            for (int i = 0; i < 3; i++) {
                if (states[test.parts[i]].confirmedGood) {
                    numGood++;
                } else if (!states[test.parts[i]].confirmedGood) {
                    indexBad = i;
                }
            }
            if (numGood == 2 && indexBad != -1) {
                states[test.parts[indexBad]].confirmedBad = true;
            }
        }
    }
    for (auto &part : states) {
        if (part.confirmedGood) {
            cout << 1;
        } else if (part.confirmedBad) {
            cout << 0;
        } else {
            cout << 2;
        }
        cout << endl;
    }
    return 0;
}