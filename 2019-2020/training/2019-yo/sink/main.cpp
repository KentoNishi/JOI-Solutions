// Test case path: [C:\Users\kento\OneDrive\Files\Downloads\2019-yo-data\2019-yo-t4]
// https://atcoder.jp/contests/joi2019yo/tasks/joi2019_yo_d

#include <bits/stdc++.h>
using namespace std;
int N;

int countZeros(vector<int> heights) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (heights[i] == 0) {
            sum++;
        }
    }
    return sum;
}

int main() {
    cin >> N;
    vector<int> heights = vector<int>(N);
    map<int, int> localMins;
    map<int, int> localMaxs;
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    if (countZeros(heights) == N) {
        cout << 0 << endl;
        return 0;
    }
    int r = 0;
    int maxSinceLast = heights[0];
    for (int i = 1; i < N - 1; i++) {
        maxSinceLast = max(maxSinceLast, heights[i]);
        if (heights[i - 1] > heights[i] && heights[i + 1] > heights[i]) {
            if (heights[i] > 0) {
                localMins[heights[i]]++;
            }
            localMaxs[maxSinceLast]++;
            maxSinceLast = 0;
        }
    }
    if (maxSinceLast > 0) {
        localMaxs[maxSinceLast]++;
    }
    int islandCount = heights[N - 1] > 0 ? 1 : 0;
    for (int i = 1; i < N; i++) {
        if (heights[i - 1] > 0 && heights[i] == 0) {
            islandCount++;
        }
    }
    cout << "Initially there are " << islandCount << endl;
    auto minsPointer = localMins.begin();
    auto maxsPointer = localMaxs.begin();
    int ans = islandCount;
    while (minsPointer != localMins.end() && maxsPointer != localMaxs.end()) {
        if (maxsPointer->first == minsPointer->first) {
            //cout << "Height " << maxsPointer->first << ": " << maxsPointer->second << " sank and " << minsPointer->second << " split off" << endl;
            islandCount -= maxsPointer->second;
            islandCount += minsPointer->second;
            minsPointer++;
            maxsPointer++;
        } else {
            if (minsPointer->first < maxsPointer->first) {
                //cout << "Height " << minsPointer->first << ": " << minsPointer->second << " split off" << endl;
                islandCount += minsPointer->second;
                minsPointer++;
            } else {
                //cout << "Height " << maxsPointer->first << ": " << maxsPointer->second << " sank" << endl;
                islandCount -= maxsPointer->second;
                maxsPointer++;
            }
        }
        ans = max(islandCount, ans);
    }
    cout << ans << endl;
    return 0;
}