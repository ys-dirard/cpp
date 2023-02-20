#include <bits/stdc++.h>
using namespace std;

// 三角形
// 
// n本の棒がある
// その中から3本選び、できるだけ周長の長い三角形を作りたい
// 最大の周長はいくつか？作れない場合は0を出力
// 
// 制約：
// 3<=n<=100
// 1<=ai<=10^8

int n;
vector<int> a(101, 0);

int main(){
    // input1
    n = 5;
    a = {2, 3, 4, 5, 10};
    // 12

    // input2
    // n = 3;
    // a = {4, 5, 10, 20};
    // 0
    
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]+a[j]>a[k] && a[j]+a[k]>a[i] && a[k]+a[i]>a[j]){
                    ans = a[i]+a[j]+a[k];
                }
            }
        }
    }
    cout << ans << endl;
    // 二本決まったら残りは三角形ができる最後の1本があるかをsortしておいたaにたいして二分探索するとO(n^2 log n)にできそう
}