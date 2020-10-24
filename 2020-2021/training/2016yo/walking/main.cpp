// Test case path: [path]
// https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_d

#include <bits/stdc++.h>
#define int64 long long
using namespace std;
int64 N, T, Q;

struct Person {
    int64 start, dir, end = INT_MAX;
};
vector<Person> people;

int main() {
    cin >> N >> T >> Q;
    people.resize(N);
    for (int i = 0; i < N; i++) {
        auto &p = people[i];
        cin >> p.start >> p.dir;
        if (p.dir == 2) p.dir = -1;
    }
    int64 lastCluster = LLONG_MIN;
    for (int i = 0; i < N; i++) {
        auto &p = people[i];
        if (p.dir == 1) {
            p.end = p.start + T;
            continue;
        }
        p.end = p.start - T;
        if (i && people[i - 1].dir == 1 && p.start - people[i - 1].start <= 2 * T) {
            p.end = (p.start + people[i - 1].start) / 2;
        }
        if (lastCluster != -INT_MAX) {
            p.end = max(p.end, lastCluster);
        }
        for (int j = i - 1; people[j].dir == 1; j--) {
            people[j].end = min(p.end, people[j].start + T);
        }
        lastCluster = p.end;
    }
    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        cout << people[a - 1].end << endl;
    }
    return 0;
}