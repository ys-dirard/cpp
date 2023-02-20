#include <iostream>
using namespace std;

int main(){
    int H, W, Q;
    int X[1509][1509], S[1509][1509];
    int A[100009], B[100009], C[100009], D[100009];

    cin >> H >> W;
    for (int i=0; i<=H; i++) {
        for (int j=0; j<=W; j++) {
            if (i!=0 && j!=0) cin >> X[i][j];
            else S[i][j] = 0;
        }
    }

    cin >> Q;
    for (int i=1; i<=Q; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    // yoko
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            S[i][j] = S[i][j-1] + X[i][j];
        }
    }

    // tate
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            S[i][j] = S[i-1][j] + S[i][j];
        }
    }

    for (int i=1;i<=Q; i++) {
        cout << S[C[i]][D[i]] + S[A[i]-1][B[i]-1] - S[A[i]-1][D[i]] - S[C[i]][B[i]-1] << endl;
    }
    return 0;
}