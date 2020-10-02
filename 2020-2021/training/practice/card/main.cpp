// Test case path: [path]
// https://atcoder.jp/contests/joi2021-practice/tasks/joi2020_practice_b

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        cout << nums[i] << (i == 0 ? "" : " ");
    }
    cout << endl;
    return 0;
}