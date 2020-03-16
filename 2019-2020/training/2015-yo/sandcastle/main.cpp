// Test case path: [path]
// https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_e

#include <bits/stdc++.h>
using namespace std;

int H, W;

struct Point {
    int x;
    int y;
};

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

queue<Point> getNextRound(queue<Point> &destroyList, vector<vector<int>> &countdowns) {
    queue<Point> nextRound;
    while (destroyList.size() > 0) {
        Point top = destroyList.front();
        destroyList.pop();
        for (int k = 0; k < 8; k++) {
            int nx = top.x + dx[k];
            int ny = top.y + dy[k];
            if (nx >= H || ny >= W || nx < 0 || ny < 0) {
                continue;
            }
            if (countdowns[nx][ny] == 0) {
                continue;
            }
            countdowns[nx][ny]--;
            if (countdowns[nx][ny] == 0) {
                nextRound.push({nx, ny});
            }
        }
    }
    return nextRound;
}

int main() {
    cin >> H >> W;
    vector<vector<int>> grid = vector<vector<int>>(H, vector<int>(W));
    queue<Point> toDestroy;
    for (int i = 0; i < H; i++) {
        char c;
        int k;
        for (int j = 0; j < W; j++) {
            cin >> c;
            if (c == '.') {
                k = 0;
                toDestroy.push({i, j});
            } else {
                k = c - '0';
            }
            grid[i][j] = k;
        }
    }
    vector<vector<int>> countdowns = grid;
    int ans = 0;
    while (toDestroy.size() > 0) {
        queue<Point> destroyList = toDestroy;
        toDestroy = getNextRound(destroyList, countdowns);
        ans++;
    }
    cout << ans - 1 << endl;
    return 0;
}