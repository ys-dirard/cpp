#include <bits/stdc++.h>
using namespace std;

int N, K;
int a[109];
bool dp[100009]; // dp[i]: 残りi個の時に勝てるか？

int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    
    for(int i=1;i<=K;i++){
        bool flg = true;
        for(int j=1;j<=N;j++){
            if(i-a[j]<0){
                continue;
            }else{
                flg &= dp[i-a[j]];
            }
        }
        dp[i] = 1 - flg;
    }

    if(dp[K]){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }
    // for(int i=0;i<=K;i++){
    //     cout << dp[i] << " ";
    // }
    cout << endl;
    return 0;
}