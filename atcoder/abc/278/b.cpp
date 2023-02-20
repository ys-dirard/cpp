/* #region convenient */
#include <bits/stdc++.h>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>
using namespace std;
/* #endregion*/

int H, M;
int A, B, C, D;

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> H >> M;
    
    A = H / 10;
    B = H % 10;
    C = M / 10;
    D = M % 10;

    while(!(10*A+C>=0 && 10*A+C<24 && 10*B+D>=0 && 10*B+D<60)){
        if(10*C+D!=59){
            D = D+1;
        }else{
            int tmp = (10*A+B+1)%24;
            A = tmp / 10;
            B = tmp % 10;
            C = D = 0;
        }
    }
    cout << 10*A + B << " " << 10*C + D << endl;
    return 0;
}