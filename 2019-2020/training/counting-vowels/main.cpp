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
    string str;
    int N;
    cin >> N;
    cin >> str;
    int i=0;
    for(char &c:str){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            i++;
        }
    }
    cout << i << endl;
    return 0;
}