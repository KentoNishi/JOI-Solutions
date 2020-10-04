// Test case path: [path]
// https://atcoder.jp/contests/joi2018yo/tasks/joi2018_yo_d

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int N;
vector<int> lengths;

int run(int minLength) {
    vector<int> shortestLongPiece = vector<int>(N + 1, INFINITY);
    shortestLongPiece[0] = minLength;
    for (int i = 0; i < N; i++) {
        int length = 0;
        for (int j = i; j >= 0 && !(j == 0 && i == N - 1); j--) {
            length += lengths[j];
            if (length >= minLength) {
                shortestLongPiece[i + 1] = min(shortestLongPiece[i + 1], max(length, shortestLongPiece[j]));
            }
        }
    }
    return shortestLongPiece[N] - minLength;
}

int main() {
    cin >> N;
    lengths = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> lengths[i];
    }
    int ans = INFINITY;
    for (int i = 0; i < N; i++) {
        int total = 0;
        for (int j = i; j < N; j++) {
            total += lengths[j];
            ans = min(ans, run(total));
        }
    }
    cout << ans << endl;
    return 0;
}