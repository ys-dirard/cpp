#include <bits/stdc++.h>
using namespace std;

// 線分上の格子点の数

/*
平面の２つの格子点P1=(x1, x2), P2=(x2, y2)が与えられる。
線分P1P2上にはP1, P2以外にいくつの格子点があるか？

制約：
-10^9<=x1,x2,y1,y2<=10^9

gcd(|x1-x2|, |y1-y2|) - 1が答えになる
→格子点全体は gcd+1 個でき、端点を引くとよい
*/

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a % b);
}

int main(){
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << gcd(abs(x1 - x2), abs(y1 - y2)) -1 << endl;
    return 0;
}