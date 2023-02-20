#include <bits/stdc++.h>
using namespace std;

// 双六

/*
双六があります。マス目には整数が書かれています。
マス目は前後に無限に続いており、０のマス目がスタートで１のマス目がゴールですが、
さいころの目にはa, b, -a, -bの４つの整数しかない。
そのため、ゴールにたどり着けない可能性もある。
４つの目をそれぞれ何回出せばゴールにたどり着けますか？
複数解が存在する場合はどれか一つを、解がなければ-1を出力してください。

制約；
1<=a,b<=10^9

解は
ax+by = 1 (a, b in Z)
となる。

bx' + (a%b)y' = gcd(a, b) の解x', y'が求まっているとすると
a % b = a - (a/b)b なので
ay' + b(x' - (a/b)y') = gcd(a, b) となる。
-> a, bの係数が入れ替わり、bの方はさらにa/bを引く！

b=0の時は
a*1 + b*0 = a = gcd(a, b) である。
*/

int extgcd(int a, int b, int& x, int& y){
    int d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else{
        x = 1;
        y = 0;
    }
    return d;
}

int main(){
    int a, b, x, y;
    cin >> a >> b;
    int d = extgcd(a, b, x, y);

    if(d==1){
        cout << max(0, x) << " " << max(0, y) << " " << max(0, -x) << " " << max(0, -y) << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}