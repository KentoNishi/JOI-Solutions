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
    sort(people.begin(), people.end(), [](Person a, Person b) {
        return a.start < b.start;
    });
    for (int i = 0; i < N - 1; i++) {
        if (people[i].velocity == 1 && people[i + 1].velocity == -1) {
            // might collide
            if (people[i + 1].start - people[i].start <= 2 * T) {
                // definitely will collide
                long long collision = (people[i].start + people[i + 1].start) / 2;
                people[i].end = collision;
                people[i + 1].end = collision;
                int j = i - 1;
                while (j >= 0 &&
                       people[j].velocity == 1 &&
                       collision - people[j].start <= T) {
                    people[j].end = collision;
                    j--;
                }
                j = i + 1;
                while (j < N &&
                       people[j].velocity == -1 &&
                       people[j].start - collision <= T) {
                    people[j].end = collision;
                    j++;
                }
                i = j - 1;
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        a--;
        cout << people[a].end << endl;
    }
    return 0;
}