#include <bits/stdc++.h>
using namespace std;

int N, K;
string S;
int c[100009][30]; // c[i][j]: Sのi文字目の右にある中で一番左にあるjのインデックス(逆順に求められる)

char int2char(int x){
    return (char)x + 'a';
}

int main(){
    cin >> N >> K >> S;
    for(int i=0;i<=N;i++){
        for(int j=0;j<26;j++){
            c[i][j] = 1<<30;
        }
    }
    
    for(int i=N-1;i>=0;i--){
        for(int j=0;j<26;j++){
            if((S[i] - 'a') == j){
                c[i][j] = i;
            }else{
                c[i][j] = c[i+1][j];
            }
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<26;j++){
    //         cout << c[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    string ans = "";
    int i = 0;
    while(ans.size()<K){
        // cout << ans << endl;
        int dif = K-ans.size();
        for(int j=0;j<26;j++){
            if(N - c[i][j] >= dif){
                ans += S[c[i][j]];
                i = c[i][j] + 1;
                break;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}