// Test case path: [path]
// url

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<char>> before = vector<vector<char>>(N, vector<char>(N));
    vector<vector<char>> after = vector<vector<char>>(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int c = 0; c < N; c++) {
            before[i][c] = s[c];
        }
    }
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int c = 0; c < N; c++) {
            after[i][c] = s[c];
        }
    }
    int noTurn = 0;
    int upsideDown = 2;
    int turnLeft = 1;
    int turnRight = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (before[i][j] != after[i][j]) {
                noTurn++;
            }
            if (before[i][j] != after[N - 1 - i][N - 1 - j]) {
                upsideDown++;
            }
            if (before[i][j] != after[j][N - 1 - i]) {
                turnRight++;
            }
            if (before[i][j] != after[N - 1 - j][i]) {
                turnLeft++;
            }
        }
    }
    cout << min(min(noTurn, upsideDown), min(turnLeft, turnRight)) << endl;
    return 0;
}