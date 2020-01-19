// Test case path: [path]
// https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_d

#include <bits/stdc++.h>
using namespace std;

int N, Q;
long long T;

struct Person {
    long long start;
    long long end;
    int velocity;
    bool seen = false;
};

int main() {
    cin >> N >> T >> Q;
    vector<Person> people;
    for (int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        Person p = Person();
        p.start = a;
        p.velocity = b == 1 ? 1 : -1;
        p.end = p.start + p.velocity * T;
        people.push_back(p);
    }
    vector<int> goingRight;
    vector<int> goingLeft;
    vector<long long> goingRightPos;
    for (int i = 0; i < N; i++) {
        if (people[i].velocity == 1) {
            goingRight.push_back(i);
            goingRightPos.push_back(people[i].start);
        } else {
            goingLeft.push_back(i);
        }
    }
    int nextR = 0;
    for (int i = 0; i < goingLeft.size();) {
        auto p = lower_bound(goingRightPos.begin(), goingRightPos.end(), people[goingLeft[i]].start);
        if (p == goingRightPos.begin() || p == goingRightPos.end()) {
            break;
        }
        int r = distance(goingRightPos.begin(), p);
        long long timeTaken = people[goingLeft[i]].start - people[goingRight[r - 1]].start;
        long long locationOfCollision = (people[goingLeft[i]].start + people[goingRight[r - 1]].start) / 2;
        for (int j = r - 1; j >= nextR; j--) {
            if (timeTaken <= 2 * T) {
                people[goingLeft[i]].end = locationOfCollision;
                people[goingRight[j]].end = locationOfCollision;
            }
        }
        i++;
        while (i < goingLeft.size() && people[goingLeft[i]].start - locationOfCollision <= T) {
            people[goingLeft[i]].end = locationOfCollision;
            i++;
        }
        nextR = r;
    }
    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        a--;
        cout << people[a].end << endl;
    }
    return 0;
}