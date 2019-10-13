// https://www.ioi-jp.org/joi/2019/2020-yo1/2020-yo1a-t3.html

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> aList=vector<int>(N);
    vector<int> bList=vector<int>(M);
    vector<int> cList=vector<int>(N+M);
    for(int i=0;i<N;i++){
        cin >> aList[i];
    }
    for(int i=0;i<M;i++){
        cin >> bList[i];
    }
    for(int i=0;i<N+M;i++){
        if(N==0 && M==0){
            return 0;
        }
        if(aList.size()==0){
            cList[i]=bList[0];
            bList.erase(bList.begin());
        }else if(bList.size()==0){
            cList[i]=aList[0];
            aList.erase(aList.begin());
        }else{
            if(bList[0]<aList[0]){
                cList[i]=bList[0];
                bList.erase(bList.begin());
            }else{
                cList[i]=aList[0];
                aList.erase(aList.begin());
            }
        }
    }
    for(auto &c:cList){
        cout << c << endl;  
    }
    return 0;
}