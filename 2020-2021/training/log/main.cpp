// Test case path: [path]
// https://atcoder.jp/contests/joi2021-practice/tasks/joi2020_practice_c

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (char c : s) {
            cout << (c < 'a' ? (char)(c - 'A' + 'a') : c);
        }
        cout << endl;
    }
    return 0;
}