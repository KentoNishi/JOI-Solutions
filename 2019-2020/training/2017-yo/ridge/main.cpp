// Test case path: [path]
// https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_e

#include <bits/stdc++.h>
using namespace std;

int H, W;

struct Pixel {
    int height;
    pair<int,int> target;
    bool ridge=false;
};

vector<vector<Pixel>> grid;

int main() {
    cin >> H >> W;
    grid = vector<vector<Pixel>>(H, vector<Pixel>(W));
    vector<pair<int,int>> order=vector<pair<int,int>>(H*W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j].height;
            grid[i][j].height--;
            order[grid[i][j].height]=make_pair(i,j);
        }
    }
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    for(int level=0;level<H*W;level++){
        int i=order[level].first;
        int j=order[level].second;
        bool pool=true;
        set<pair<int,int>> targets;
        for(int d=0;d<4;d++){
            if(i+dy[d]<H && i+dy[d]>=0 && j+dx[d]<W && j+dx[d]>=0){
                if(grid[i+dy[d]][j+dx[d]].ridge){
                    grid[i][j].ridge=true;
                    break;
                }
                if(grid[i+dy[d]][j+dx[d]].height<grid[i][j].height){
                    targets.insert(grid[i+dy[d]][j+dx[d]].target);
                }
            }
        }
        if(targets.size()==0){
            targets.insert(make_pair(i,j));
        }
        if(targets.size()==1){
            grid[i][j].target=*targets.begin();
        }else if(targets.size()>1){
            grid[i][j].ridge=true;
        }
    }
    int ans=0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if(grid[i][j].ridge){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}