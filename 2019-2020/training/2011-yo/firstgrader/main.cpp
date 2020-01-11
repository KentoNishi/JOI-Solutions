// Test case path: [path]
// https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_d

#include <bits/stdc++.h>
using namespace std;

int N;
int nums[99];
int finalAns;
long long dp[100][21];
// index, sum = ways to get here

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> nums[i];
    }
    cin >> finalAns;
    dp[0][nums[0]] = 1;
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j <= 20; j++) {
            int plus = j + nums[i + 1];
            int minus = j - nums[i + 1];
            if (plus <= 20) {
                dp[i + 1][plus] += dp[i][j];
            }
            if (j - nums[i + 1] >= 0) {
                dp[i + 1][minus] += dp[i][j];
            }
        }
    }
    cout << dp[N - 2][finalAns] << endl;
    return 0;
}