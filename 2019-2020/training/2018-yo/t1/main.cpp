// https://www.ioi-jp.org/joi/2017/2018-yo/2018-yo-t1.html

#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    int amount1 = ceil((float)N / A);
    int price1 = amount1 * B;
    int amount2 = ceil((float)N / C);
    int price2 = amount2 * D;
    cout << min(price1, price2) << endl;
    return 0;
}