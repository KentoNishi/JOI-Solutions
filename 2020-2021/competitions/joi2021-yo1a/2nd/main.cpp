// Test case path: [path]
// https://atcoder.jp/contests/joi2021-yo1a/tasks/joi2021_yo1a_a

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int main() {
    vector<int> nums = vector<int>(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    sort(nums.begin(), nums.end());
    cout << nums[1] << endl;
    return 0;
}