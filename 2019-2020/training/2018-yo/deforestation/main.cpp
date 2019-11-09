// Test case path: [C:\Users\kento\OneDrive\Files\Documents\GitHub\JOI-Solutions\2019-2020\training\2018-yo\2018-yo\2018-yo-t5]
// https://atcoder.jp/contests/joi2018yo/tasks/joi2018_yo_e

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int H,W;

struct Cell{
    int num;
    bool visited=false;
    Cell(bool num){
        this->num=num;
    }
    Cell(){
    }
};

int steps(vector<vector<Cell>> grid,int i, int j,int count){
    if(grid[i][j].visited){
        // if already visited, return -1
        return -1;
    }
    grid[i][j].visited=true;
    // do not visit the same node again.
    int movesToClearCell=2*(count-1)*grid[i][j].num+grid[i][j].num;
    // the number of moves to clear the current cell.
    if(i==H-1 && j==W-1){
        // if at the bottom right corner, 
        // return the number of steps
        // needed to carry the trees in the
        // cell back home 
        return movesToClearCell;
    }
    if(grid[i][j].num>0){
        grid[i][j].num=0;
        return steps(grid,0,0,count+movesToClearCell)
    }
    count++;
}

int main() {
    cin >> H >> W;
    vector<vector<Cell>> grid;
    grid.resize(H,vector<Cell>(W));
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            cin >> grid[h][w].num;
        }
    }
    cout << steps(grid,0,0,0) << endl;
    return 0;
}