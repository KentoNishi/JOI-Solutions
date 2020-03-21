// Test case path: [path]
// https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_e

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int N, D;

struct Point {
    int x, y, z;
    bool operator!=(const Point &other) const {
        return !(*this == other);
    }
    bool operator==(const Point &other) const {
        return (x == other.x && y == other.y && z == other.z);
    }
    bool operator<(const Point &other) const {
        return (x < other.x && y < other.y && z < other.z);
    }
    bool operator>(const Point &other) const {
        return (x > other.x && y > other.y && z > other.z);
    }
};

struct Box {
    Point p1, p2;
};

struct Overlap {
    Box box;
    int layers;
};

vector<Overlap> overlaps;

Box getIntersection(Box b1, Box b2) {
    Box intersection = {{0, 0, 0}, {0, 0, 0}};
    if (b1.p1 < b2.p1 && b1.p2 > b2.p1) {
        intersection.p1 = b2.p1;
        intersection.p2 = b1.p2;
    } else if (b2.p1 < b1.p1 && b2.p2 > b1.p1) {
        intersection.p1 = b1.p1;
        intersection.p2 = b2.p2;
    }
    return intersection;
}

long long getVolume(Box box) {
    return abs(box.p1.x - box.p2.x) * abs(box.p1.y - box.p2.y) * abs(box.p1.z - box.p2.z);
}

int main() {
    cin >> N >> D;
    vector<Box> bounds;
    for (int i = 0; i < N; i++) {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        bounds.push_back({{a, b, c}, {d, e, f}});
        overlaps.push_back({bounds[i], 1});
    }
    long long ans = 0;
    for (auto &bound : bounds) {
        for (auto &overlap : overlaps) {
            Box intersection = getIntersection(overlap.box, bound);
            if (intersection.p1 != intersection.p2) {
                overlaps.push_back({intersection, overlap.layers + 1});
                if (overlap.layers + 1 == D) {
                    ans += getVolume(intersection);
                }
            }
        }
    }
    for (auto &overlap : overlaps) {
        cout << overlap.layers << ": " << overlap.box.p1.x << "," << overlap.box.p1.y << "," << overlap.box.p1.z << " " << overlap.box.p2.x << "," << overlap.box.p2.y << "," << overlap.box.p2.z << " " << endl;
    }
    cout << ans << endl;
    return 0;
}