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

int64 findAns(vector<Item> &leftSide, vector<Item> &rightSide) {
    int64 ans = 0;
    int64 lowerBound = 0, upperBound = 0, index = 0;
    multiset<int64> sortedByBruno;
    while (lowerBound < leftSide.size() && index < rightSide.size()) {
        int64 query = rightSide[index].annaValue;
        int64 queryMin = query - D;
        int64 queryMax = query + D;
        while (lowerBound < leftSide.size() && leftSide[lowerBound].annaValue < queryMin) {
            sortedByBruno.erase(leftSide[lowerBound].brunoValue);
            lowerBound++;
        }
        upperBound = max(upperBound, lowerBound);
        while (upperBound < leftSide.size() && leftSide[upperBound].annaValue <= queryMax) {
            sortedByBruno.insert(leftSide[upperBound].brunoValue);
            upperBound++;
        }
        if (sortedByBruno.size() > 0) {
            auto front = sortedByBruno.begin();
            auto back = sortedByBruno.end();
            back--;
            int64 top = *front;
            int64 bottom = *back;
            int64 myValue = rightSide[index].brunoValue;
            ans = max(ans, abs(myValue - top));
            ans = max(ans, abs(myValue - bottom));
        }
        index++;
    }
    return ans;
}

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
    vector<Item> &leftSide = permutations[0];
    vector<Item> &rightSide = permutations[1];
    cout << findAns(leftSide, rightSide) << endl;
    return 0;
}
