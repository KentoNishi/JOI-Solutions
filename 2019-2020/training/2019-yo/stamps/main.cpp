// Test case path: [path]
// https://atcoder.jp/contests/joi2019yo/tasks/joi2019_yo_c

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<bool> sequence = vector<bool>(N);
    string line;
    cin >> line;
    for (int i = 0; i < N; i++) {
        sequence[i] = line[i] == 'O';
    }
    int ans = 0;
    for (int i = 1; i < N;) {
        int k = i;
        while (k < N && sequence[k] != sequence[k - 1]) {
            k++;
        }
        ans += round((k - i) / 2.0);
        if (i == k) {
            i++;
        } else {
            i = k;
        }
    }
    cout << ans << endl;
    return 0;
}