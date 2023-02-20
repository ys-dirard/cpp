#include <bits/stdc++.h>
using namespace std;

int H, W, A[2009][2009];
int Si[2009], Sj[2009];

int main(){
    cin >> H >> W;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> A[i][j];
        }
    }
    for(int i=0;i<=H;i++) Si[0] = 0;
    for(int i=0;i<=W;i++) Sj[0] = 0;
    
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            Si[i] += A[i][j];
            Sj[j] += A[i][j];
        }
    }

    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            int ans = Si[i] + Sj[j] - A[i][j];
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}