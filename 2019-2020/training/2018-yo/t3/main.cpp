// // https://www.ioi-jp.org/joi/2017/2018-yo/2018-yo-t3.html

#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
int H, W;
// H is y, W is x

int findSum(int linex, int liney, vector<vector<int>> &grid) {
    int sum = 0;
    for (int x = 0; x <W;x++){
        for(int y=0;y<H;y++){
            sum+=min(abs(liney-y),abs(linex-x))*grid[x][y];
        }
    }
    return sum;
}

int main() {
    cin >> H >> W;
    vector<vector<int>> grid(W, vector<int>(H));
    // grid[x][y]
    for (int i = 0; i < H; i++) {
        for (int k = 0; k < W; k++) {
            cin >> grid[k][i];
        }
    }
    int ans=INFINITY;
    for (int liney = 0; liney < H; liney++) {
        for (int linex = 0; linex < W; linex++) {
            int localAns = findSum(linex, liney, grid);
            ans = min(ans, localAns);
        }
    }
    cout << ans << endl;
    return 0;
}