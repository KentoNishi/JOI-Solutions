// Test case path: [path]
// https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_e

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int N, D;

struct Point {
    int64 x, y, z;
    bool operator>=(const Point &other) const {
        return (x >= other.x && y >= other.y && z >= other.z);
    }
    bool operator<=(const Point &other) const {
        return (x <= other.x && y <= other.y && z <= other.z);
    }
};

struct Box {
    Point p1, p2;
};

int64 getVolume(Box box) {
    return abs(box.p1.x - box.p2.x) * abs(box.p1.y - box.p2.y) * abs(box.p1.z - box.p2.z);
}

bool inside(Box in, Box out) {
    return in.p1 >= out.p1 && in.p2 <= out.p2;
}

int main() {
    cin >> N >> D;
    vector<Box> bounds = vector<Box>(N);
    for (int i = 0; i < N; i++) {
        int64 a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        bounds[i] = {{a, b, c}, {d, e, f}};
    }
    vector<int64> allX = vector<int64>(N * 2);
    vector<int64> allY = allX;
    vector<int64> allZ = allX;
    for (int i = 0; i < N; i++) {
        Box &box = bounds[i];
        allX[2 * i] = box.p1.x;
        allY[2 * i] = box.p1.y;
        allZ[2 * i] = box.p1.z;
        allX[2 * i + 1] = box.p2.x;
        allY[2 * i + 1] = box.p2.y;
        allZ[2 * i + 1] = box.p2.z;
    }
    sort(allX.begin(), allX.end());
    sort(allY.begin(), allY.end());
    sort(allZ.begin(), allZ.end());
    int64 ans = 0;
    for (int i = 0; i < 2 * N - 1; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            for (int k = 0; k < 2 * N - 1; k++) {
                Box box = {{allX[i], allY[j], allZ[k]},
                           {allX[i + 1], allY[j + 1], allZ[k + 1]}};
                int overlap = 0;
                for (int m = 0; m < N; m++) {
                    if (inside(box, bounds[m])) {
                        overlap++;
                    }
                }
                if (overlap >= D) {
                    ans += getVolume(box);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}