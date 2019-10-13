// https://www.ioi-jp.org/joi/2019/2020-yo1/2020-yo1a-t1.html

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if(a+b+c<=4){
        cout << 1 << endl;
    }else{
        cout << 2 << endl;
    }
    return 0;
}