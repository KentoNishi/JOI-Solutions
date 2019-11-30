#include <stdio.h>
int map[1002][1002];
int dat[1002][1002];
int x[1000001], y[1000001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    int mx, my;
    scanf("%d%d", &mx, &my);
    for (int i = 0; i < mx + 2; i++)
        for (int j = 0; j < my + 2; j++)
            map[i][j] = 1000000000, dat[i][j] = 0;
    for (int i = 0; i < mx; i++)
        for (int j = 0; j < my; j++)
            scanf("%d", &map[i + 1][j + 1]);
    for (int i = 1; i <= mx; i++)
        for (int j = 1; j <= my; j++)
            x[map[i][j]] = i, y[map[i][j]] = j;
    int c = 0;
    for (int i = 1; i <= mx * my; i++) {
        int r = 0;
        for (int j = 0; j < 4; j++) {
            int a = x[i] + dx[j], b = y[i] + dy[j];
            if (map[a][b] < i) {
                if (r == 0)
                    r = dat[a][b];
                else if (r != dat[a][b])
                    r = -1;
            }
        }
        if (r == 0)
            dat[x[i]][y[i]] = i;
        else
            dat[x[i]][y[i]] = r;
        if (r == -1)
            c++;
    }
    printf("%d\n", c);
}