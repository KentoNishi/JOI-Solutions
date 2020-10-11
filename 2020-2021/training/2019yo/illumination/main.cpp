// Test case path: [path]
// https://atcoder.jp/contests/joi2019yo/tasks/joi2019_yo_e

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int N, M;
vector<int64> trees;
vector<int64> nearestBorder;
vector<int64> dp;

int main() {
    cin >> N >> M;
    trees.resize(N);
    nearestBorder.resize(N + 1);
    dp.resize(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
        nearestBorder[i + 1] = i;
    }
    for (int i = 0; i < M; i++) {
        int64 l, r;
        cin >> l >> r;
        nearestBorder[r] = min(nearestBorder[r], l - 1);
    }
    for (int i = N - 1; i >= 1; i--) {
        nearestBorder[i] = min(nearestBorder[i], nearestBorder[i + 1]);
    }
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        dp[i] = max(dp[i - 1], dp[nearestBorder[i]] + trees[i - 1]);
    }
    cout << dp[N] << endl;
    return 0;
}