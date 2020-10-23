// Test case path: [path]
// https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_e

#include <bits/stdc++.h>
#define int64 long long
using namespace std;
int grid[1000][1000];

struct Area {
    int x, y;
};
const bool operator<(const Area &a1, const Area &a2) {
    return grid[a1.x][a1.y] < grid[a2.x][a2.y];
}

set<Area> dp[1000][1000];
int N, M;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<Area> areas;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            areas.push_back({i, j});
        }
    }
    sort(areas.begin(), areas.end());
    int ans = 0;
    for (Area &a : areas) {
        auto &d = dp[a.x][a.y];
        if (d.size() >= 2) ans++;
        if (d.size() == 0) d.insert({a.x, a.y});
        for (int i = 0; i < 4; i++) {
            int nx = a.x + dx[i];
            int ny = a.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || grid[nx][ny] < grid[a.x][a.y]) continue;
            auto &d2 = dp[nx][ny];
            d2.insert(d.begin(), d.end());
        }
        d.clear();
    }
    cout << ans << endl;
    return 0;
}