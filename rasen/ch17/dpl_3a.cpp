#include <bits/stdc++.h>
using namespace std;

int H, W;
int c[1409][1409];
int S[1409][1409];

int main(){
    cin >> H >> W;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> c[i][j];
        }
    }
    for(int i=0;i<=H;i++){
        for(int j=0;j<=W;j++){
            S[i][j] = 0;
        }
    }

    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            S[i][j] = S[i][j-1] + c[i][j]; 
        }
    }
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            S[i][j] += S[i-1][j]; 
        }
    }
    // for(int i=0;i<=H;i++){
    //     for(int j=0;j<=W;j++){
    //         cout << S[i][j] << " "; 
    //     }
    //     cout << endl;
    // }

    int max_l = 0;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            while(i+max_l<=H && j+max_l<=W){
                int tmp = S[i-1][j-1] + S[i+max_l][j+max_l] - S[i-1][j+max_l] - S[i+max_l][j-1];
                if(tmp==0){
                    max_l++;
                }else{
                    break;
                }
            }
        }
    }

    cout << max_l * max_l << endl;
    return 0;
}