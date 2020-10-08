// Test case path: [path]
// https://atcoder.jp/contests/joi2018yo/tasks/joi2018_yo_e

#include <bits/stdc++.h>
#define int64 int
using namespace std;

int H, W;

vector<vector<vector<int>>> dp;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<vector<int>> trees;

int main() {
    cin >> H >> W;
    dp = vector<vector<vector<int>>>(H, vector<vector<int>>(W, vector<int>(H * W + 1, INT_MAX)));
    trees = vector<vector<int>>(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> trees[i][j];
        }
    }
    dp[0][0][0] = 0;
    for (int dist = 0; dist < H * W; dist++) {
        for (int x = 0; x < H; x++) {
            for (int y = 0; y < W; y++) {
                if (dp[x][y][dist] == INT_MAX) {
                    continue;
                }
                for (int i = 0; i < 4; i++) {
                    int nx = dx[i] + x;
                    int ny = dy[i] + y;
                    if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                        continue;
                    }
                    dp[nx][ny][dist + 1] = min(dp[nx][ny][dist + 1], dp[x][y][dist] + (2 * dist + 1) * trees[nx][ny] + 1);
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= H * W; i++) {
        ans = min(ans, dp[H - 1][W - 1][i] - i);
    }
    cout << ans << endl;
    return 0;
}