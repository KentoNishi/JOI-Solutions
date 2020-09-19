// Test case path: [path]
// https://atcoder.jp/contests/joi2021-yo1a/tasks/joi2021_yo1a_c

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    unordered_set<int> num1;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        num1.insert(a);
    }
    set<int> num2;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        num2.insert(a);
    }
    for (auto a : num2) {
        if (num1.find(a) != num1.end()) {
            cout << a << endl;
        }
    }
    return 0;
}