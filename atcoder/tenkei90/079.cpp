#include <bits/stdc++.h>
using namespace std;
#define ll long long

int H, W;
ll A[109][109], B[109][109];

int main(){
    cin >> H >> W;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> A[i][j];
        }
    }
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> B[i][j];
        }
    }

    ll ans = 0;
    for(int i=1;i<H;i++){
        for(int j=1;j<W;j++){
            ll diff = A[i][j] - B[i][j];
            ans += abs(diff);
            A[i][j] -= diff;
            A[i+1][j] -= diff;
            A[i][j+1] -= diff;
            A[i+1][j+1] -= diff;
        }
    }
    bool flg = true;
    for(int i=1;i<=H;i++){
        if(A[i][W] != B[i][W]) flg = false;
    }
    for(int j=1;j<=W;j++){
        if(A[H][j] != B[H][j]) flg = false;
    }

    if(flg) cout << "Yes" << endl << ans << endl;
    else cout << "No" << endl; 
    return 0;
}