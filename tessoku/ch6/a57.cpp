#include <bits/stdc++.h>
using namespace std;

int N,Q,A[100009],X[100009],Y[100009];
int d[32][100009];

int main(){
    cin >> N >> Q;
    for(int i=1;i<=N;i++) {
        cin >> A[i];
        d[1][i] = A[i];
    }
    for(int i=1;i<=Q;i++) cin >> X[i] >> Y[i];

    for(int i=2;i<=30;i++){
        for(int j=1;j<=N;j++) {
            d[i][j] = d[i-1][d[i-1][j]];
        }
    }

    for(int i=1;i<=Q;i++){
        // int tmp = Y[i];
        int pos = X[i];
        for(int j=0;j<30;j++){
            if(Y[i] & (1 << j)) pos = d[j+1][pos];
        }
        cout << pos << endl;
    }
    return 0;
}