// Test case path: [path]
// https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_e

#include <bits/stdc++.h>
#define int68 long long
using namespace std;

int H, W;
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct Pixel {
    int init = 0;
    int wrap = 0;
};

vector<vector<Pixel>> grid;

struct State {
    int x, y;
};

queue<State> q;
auto q2 = q;

int main() {
    cin >> H >> W;
    grid = vector<vector<Pixel>>(H + 1, vector<Pixel>(W + 1));
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            char c;
            cin >> c;
            if (c == '.') c = '0';
            grid[x][y].init = c - '0';
        }
    }
    for (int x = 1; x < H - 1; x++) {
        for (int y = 1; y < W - 1; y++) {
            for (int k = 0; k < 8; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (grid[nx][ny].init == 0) grid[x][y].wrap++;
            }
            if (grid[x][y].init != 0 && grid[x][y].wrap >= grid[x][y].init) {
                q.push({x, y});
            }
        }
    }
    int ans = 0;
    while (q.size() > 0) {
        while (q.size() > 0) {
            auto &top = q.front();
            q.pop();
            for (int k = 0; k < 8; k++) {
                int nx = top.x + dx[k], ny = top.y + dy[k];
                grid[nx][ny].wrap++;
                if (grid[nx][ny].init != 0 && grid[nx][ny].wrap == grid[nx][ny].init) {
                    q2.push({nx, ny});
                }
            }
        }
        ans++;
        swap(q, q2);
    }
    cout << ans << endl;
}