// Test case path: [path]
// https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_f

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

struct Item {
    int64 annaValue;
    int64 brunoValue;
};

vector<Item> items;
vector<vector<Item>> permutations;
int64 N, D;

void halfEnum(int64 side, int64 index, int64 upper, Item total) {
    if (index == upper) {
        permutations[side].push_back(total);
        return;
    }
    Item thisSide = total;
    thisSide.annaValue += items[index].annaValue;
    thisSide.brunoValue += items[index].brunoValue;
    Item otherSide = total;
    otherSide.annaValue -= items[index].annaValue;
    otherSide.brunoValue -= items[index].brunoValue;
    halfEnum(side, index + 1, upper, total);
    halfEnum(side, index + 1, upper, thisSide);
    halfEnum(side, index + 1, upper, otherSide);
}

struct compare {
    bool operator()(Item a, Item b) const {
        return a.annaValue < b.annaValue;
    }
};

int main() {
    cin >> N >> D;
    items.resize(N);
    for (int64 i = 0; i < N; i++) {
        cin >> items[i].annaValue >> items[i].brunoValue;
    }
    int64 leftSize = N / 2;
    int64 rightSize = N - leftSize;
    permutations.resize(2);
    halfEnum(0, 0, N / 2, {0, 0});
    halfEnum(1, N / 2, N, {0, 0});
    sort(permutations[0].begin(), permutations[0].end(), compare());
    sort(permutations[1].begin(), permutations[1].end(), compare());
    int64 ans = 0;
    for (int64 i = 0; i < permutations[0].size(); i++) {
        Item lowerBound = permutations[0][i];
        lowerBound.annaValue -= D;
        vector<Item> &otherSide = permutations[1];
        Item upperBound = permutations[0][i];
        upperBound.annaValue += D;
        vector<Item>::iterator iter1 = lower_bound(otherSide.begin(), otherSide.end(), lowerBound, compare());
        while (iter1 != otherSide.end() && iter1->annaValue <= upperBound.annaValue) {
            ans = max(ans, abs(iter1->brunoValue - permutations[0][i].brunoValue));
            iter1++;
        }
    }
    cout << ans << endl;
    return 0;
}
