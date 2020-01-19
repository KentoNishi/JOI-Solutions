// Test case path: [path]
// https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_d

#include <bits/stdc++.h>
using namespace std;

int N, Q;
long long T;

struct Person {
    long long initialPos;
    int velocity;
    long long finalPos;
};

bool comp(Person a, Person b) {
    return a.initialPos < b.initialPos;
}

int main() {
    cin >> N >> T >> Q;
    vector<Person> goingLeft;
    vector<Person> goingRight;
    vector<pair<int, int>> people;
    for (int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        Person person = Person();
        person.initialPos = a;
        person.velocity = b == 1 ? 1 : -1;
        person.finalPos = person.initialPos + person.velocity * T;
        if (person.velocity == 1) {
            people.push_back({0, goingRight.size()});
            goingRight.push_back(person);
        } else {
            people.push_back({1, goingLeft.size()});
            goingLeft.push_back(person);
        }
    }
    sort(goingLeft.begin(), goingLeft.end(), comp);
    sort(goingRight.begin(), goingRight.end(), comp);
    vector<long long> goingRightInits = vector<long long>(goingRight.size());
    for (int i = 0; i < goingRight.size(); i++) {
        goingRightInits[i] = goingRight[i].initialPos;
    }
    for (int i = 0; i < goingLeft.size(); i++) {
        auto point = lower_bound(goingRightInits.begin(), goingRightInits.end(), goingLeft[i].initialPos);
        if (point == goingRightInits.begin() || point == goingRightInits.end()) {
            continue;
        }
        point--;
        int r = distance(goingRightInits.begin(), point);
        while (goingLeft[i].initialPos - goingRight[r].initialPos <= 2 * T) {
            goingLeft[i].finalPos = max(goingLeft[i].finalPos, goingLeft[i].initialPos - (goingLeft[i].initialPos - goingRight[r].initialPos) / 2);
            goingRight[r].finalPos = min(goingRight[r].finalPos, goingRight[r].initialPos + (goingLeft[i].initialPos - goingRight[r].initialPos) / 2);
            if (r == 0) {
                break;
            }
            r--;
        }
    }
    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        a--;
        if (people[a].first == 0) {
            cout << goingRight[people[a].second].finalPos << endl;
        } else {
            cout << goingLeft[people[a].second].finalPos << endl;
        }
    }
    return 0;
}