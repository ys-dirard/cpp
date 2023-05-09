#include <bits/stdc++.h>
using namespace std;

// xを小数i桁目で四捨五入
// 52417.6392
// i:-3
// 50000
// i:-2
// 52000
// i:-1
// 52400
// i:0
// 52420
// i:1
// 52418
// i:2
// 52417.6
// i:3
// 52417.6
double round_(double x, int i){
    double d = pow(10, i-1);
    // cout << "i:" << i << endl;
    double eps = 0.0000005;
    return round(x*d+eps)/d;
}

int main(){
    double x;
    cin >> x;
    for(int i=-3;i<=3;i++){
        cout << round_(x, i) << endl;
    }
    return 0;
}