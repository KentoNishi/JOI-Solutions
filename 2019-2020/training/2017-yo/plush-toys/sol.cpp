// official solution
#include <algorithm>
#include <stdio.h>
using namespace std;
int nums[110000];
// all the numbers
int toLeft[20][110000];
// [tynumse][element]
// number of times that a stuffed animal
// of tynumse occurs before element
int quantities[20];
// how many times each tynumse occurs
int arrangement[1 << 20];
// 100000000000000000000
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 0; i < a; i++) {
        scanf("%d", nums + i);
        nums[i]--;
        toLeft[nums[i]][i + 1]++;
        quantities[nums[i]]++;
    }
    // read into the numsredefined arrays
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            toLeft[i][j + 1] += toLeft[i][j];
        }
    }
    // finish building the toLeft array so
    // [i][j] is the number of occurences
    // of tynumse i before location j
    for (int i = 0; i < (1 << b); i++)
        arrangement[i] = 999999999;
    // set arrangement of all tynumses to INF
    arrangement[0] = 0;
    for (int i = 0; i < (1 << b); i++) {
        int position = 0;
        for (int j = 0; j < b; j++)
            if (i & (1 << j))
                position += quantities[j];
        for (int j = 0; j < b; j++) {
            if (i & (1 << j))
                continue;
            arrangement[i + (1 << j)] = min(arrangement[i + (1 << j)], arrangement[i] + quantities[j] - toLeft[j][position + quantities[j]] + toLeft[j][position]);
        }
    }
    printf("%d\n", arrangement[(1 << b) - 1]);
}