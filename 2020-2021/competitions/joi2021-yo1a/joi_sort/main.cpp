// Test case path: [path]
// https://atcoder.jp/contests/joi2021-yo1a/tasks/joi2021_yo1a_b

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    map<char, int> counts;
    for (char &c : s) {
        counts[c]++;
    }
    for (int i = 0; i < counts['J']; i++) {
        cout << 'J';
    }
    for (int i = 0; i < counts['O']; i++) {
        cout << 'O';
    }
    for (int i = 0; i < counts['I']; i++) {
        cout << 'I';
    }
    cout << endl;
    return 0;
}