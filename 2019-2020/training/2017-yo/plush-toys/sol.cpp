// official solution
#include <algorithm>
#include <stdio.h>
using namespace std;
int p[110000];
// all the numbers
int sum[20][110000];
// [type][element]
// number of times that a stuffed animal
// of type occurs before element
int sz[20];
// how many times each type occurs
int dp[1 << 20];
// 100000000000000000000
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 0; i < a; i++) {
        scanf("%d", p + i);
        p[i]--;
        sum[p[i]][i + 1]++;
        sz[p[i]]++;
    }
    // read into the predefined arrays
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            sum[i][j + 1] += sum[i][j];
        }
    }
    // finish building the sum array so
    // [i][j] is the number of occurences
    // of type i before location j
    for (int i = 0; i < (1 << b); i++)
        dp[i] = 999999999;
    // set dp of all types to INF
    dp[0] = 0;
    for (int i = 0; i < (1 << b); i++) {
        int pos = 0;
        for (int j = 0; j < b; j++)
            if (i & (1 << j))
                pos += sz[j];
        for (int j = 0; j < b; j++) {
            if (i & (1 << j))
                continue;
            dp[i + (1 << j)] = min(dp[i + (1 << j)], dp[i] + sz[j] - sum[j][pos + sz[j]] + sum[j][pos]);
        }
    }
    printf("%d\n", dp[(1 << b) - 1]);
}