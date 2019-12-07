// Test case path: [path]
// https://atcoder.jp/contests/joi2019yo/tasks/joi2019_yo_d

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> heights = vector<int>(N);
    set<int> toTest = {0};
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    bool all0 = true;
    for (int i = 0; i < N; i++) {
        if (heights[i] > 0) {
            all0 = false;
            break;
        }
    }
    if (all0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i < N - 1; i++) {
        if (heights[i - 1] > heights[i] && heights[i + 1] > heights[i]) {
            toTest.insert(heights[i]);
        }
    }
    int ans = 1;
    for (auto test : toTest) {
        int localAns = 0;
        for (int i = 1; i < N; i++) {
            if (heights[i - 1] > test && heights[i] <= test) {
                localAns++;
            }
        }
        ans = max(ans, localAns + (heights[N - 1] > test ? 1 : 0));
    }
    cout << ans << endl;
    return 0;
}