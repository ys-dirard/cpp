#include <bits/stdc++.h>
using namespace std;

// subsequence

// 長さnの数列a0, ..., a(n-1)が与えられる
// 連続する部分列で、総和がS以上となるようなもののうち
// 最小の長さを求める
// 存在しなければ0を出力する

int n, S;
int a[100009];
int s[100009]; // 累積和

int main(){
    cin >> n >> S;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i){
            s[i] = s[i-1] + a[i];
        }else{
            s[i] = a[i];
        }
    }

    int l = 0, r = 0;
    int ans = 1e9;
    while(l<n){
        while(r<n && s[r]-s[l]+a[l]<S){
            r++;
        }
        if(s[r]-s[l]+a[l]>=S){
            ans = min(ans, r-l+1);
        }
        l++;
    }
    if(ans>n){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}