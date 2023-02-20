#include <bits/stdc++.h>
using namespace std;

long long N, A[100009], B[100009], C[100009];
long long amari[3][46];

int main(){
    for(int i=0;i<3;i++){
        for(int j=0;j<46;j++){
            amari[i][j] = 0;
        }
    }
    
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=N;i++) cin >> B[i];
    for(int i=1;i<=N;i++) cin >> C[i];

    for(int i=1;i<=N;i++){
        amari[0][A[i]%46]++;
        amari[1][B[i]%46]++;
        amari[2][C[i]%46]++;
    }

    long long ans = 0;
    for(int i=0;i<46;i++){
        for(int j=0;j<46;j++){
            for(int k=0;k<46;k++){
                if((i+j+k)%46==0){
                    ans += amari[0][i]*amari[1][j]*amari[2][k];
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}