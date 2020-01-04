// Test case path: [C:\Users\kento\Downloads\2020-yo2-data\2020-yo2-t4]
// https://atcoder.jp/contests/joi2020yo2/tasks/joi2020_yo2_d

#include <bits/stdc++.h>
using namespace std;

int M, R;

int getNumber(int x, int y) {
    if (x == 0 && y == 0) {
        return 0;
    } else {
        return 3 * (y - 1) + x + 1;
    }
}

pair<int, int> getCoords(int n) {
    if (n == 0) {
        return {0, 0};
    } else {
        return {(n - 1) % 3, (n - 1) / 3 + 1};
    }
}

bool isValid(int x, int y) {
    if (y == 0) {
        return x == 0;
    } else if (y > 0 && y <= 3 && x >= 0 && x <= 2) {
        return true;
    }
    return false;
}

int main() {
    cin >> M >> R;
    queue<tuple<int, int, int>> toCheck;
    // remainder, current number, time taken
    toCheck.emplace(0, 0, 0);
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    vector<vector<bool>> visited = vector<vector<bool>>(M, vector<bool>(10));
    while (toCheck.size() > 0) {
        int remainder, currentNumber, timeTaken;
        tie(remainder, currentNumber, timeTaken) = toCheck.front();
        toCheck.pop();
        if (visited[remainder][currentNumber]) {
            continue;
        }
        visited[remainder][currentNumber] = true;
        int newRemainder = (remainder * 10 + currentNumber) % M;
        //cout << timeTaken << endl;
        //cout << remainder << " " << currentNumber << " " << timeTaken << endl;
        if (newRemainder == R) {
            cout << timeTaken + 1 << endl;
            return 0;
        }
        toCheck.emplace(newRemainder, currentNumber, timeTaken + 1);
        pair<int, int> currentCoords = getCoords(currentNumber);
        for (int i = 0; i < 4; i++) {
            int x = currentCoords.first + dx[i];
            int y = currentCoords.second + dy[i];
            if (isValid(x, y)) {
                toCheck.emplace(remainder, getNumber(x, y), timeTaken + 1);
            }
        }
    }
    return 0;
}