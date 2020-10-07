// Test case path: [path]
// https://atcoder.jp/contests/joi2018yo/tasks/joi2018_yo_e

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int H, W;
vector<vector<int>> trees;

struct State {
    bool visited = false;
    int time = INFINITY;
    int dist = INFINITY;
    int trees;
};

vector<vector<State>> dp;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

State& time(int x, int y) {
    State& me = dp[x][y];
    if (!me.visited) {
        me.visited = true;
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                continue;
            }
            State& from = time(nx, ny);
            int time = from.time + (2 * from.dist + 1) * me.trees + 1;
            int dist = from.dist + 1;
            if (time < me.time || (time == me.time && dist < me.dist)) {
                me.time = time;
                me.dist = dist;
            }
        }
    }
    return me;
}

int main() {
    cin >> H >> W;
    dp = vector<vector<State>>(H, vector<State>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> dp[i][j].trees;
        }
    }
    dp[0][0].visited = true;
    dp[0][0].dist = 0;
    dp[0][0].time = 0;
    cout << time(H - 1, W - 1).time - time(H - 1, W - 1).dist << endl;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << dp[i][j].time << "(" << dp[i][j].dist << ") ";
        }
        cout << endl;
    }
    return 0;
}