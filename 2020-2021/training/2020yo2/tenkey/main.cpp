// Test case path: [path]
// https://atcoder.jp/contests/joi2020yo2/tasks/joi2020_yo2_d

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int M, R;

int numpad[4][3] = {
    {7, 8, 9},
    {4, 5, 6},
    {1, 2, 3},
    {0, -1, -1}};

struct Item {
    int number;
    int moves = 0;
    int x, y;
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<vector<bool>> visited;

int main() {
    cin >> M >> R;
    visited = vector<vector<bool>>(M, vector<bool>(10));
    queue<Item> q;
    Item next;
    next.number = 0;
    next.x = 3;
    next.y = 0;
    q.push(next);
    while (q.size() > 0) {
        Item &front = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = front.x + dx[i];
            int ny = front.y + dy[i];
            if (nx >= 0 && ny >= 0 && nx <= 3 && ny <= 2 && numpad[nx][ny] != -1) {
                next = front;
                next.moves++;
                next.x = nx;
                next.y = ny;
                if (!visited[next.number][numpad[next.x][next.y]]) {
                    q.push(next);
                    visited[next.number][numpad[next.x][next.y]] = true;
                }
            }
        }
        next = front;
        next.moves++;
        next.number *= 10;
        next.number += numpad[front.x][front.y];
        next.number %= M;
        if (next.number == R) {
            cout << next.moves << endl;
            return 0;
        }
        if (!visited[next.number][numpad[front.x][front.y]]) {
            q.push(next);
            visited[next.number][numpad[front.x][front.y]] = true;
        }
    }
    return 0;
}