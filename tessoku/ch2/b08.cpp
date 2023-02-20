#include <iostream>
using namespace std;

int main(){
    int N, Q;
    int X[1509][1509], S[1509][1509];
    int A[100009], B[100009], C[100009], D[100009];

    cin >> N;
    for (int i=0; i<=1500; i++) {
        for (int j=0; j<=1500; j++) {
            X[i][j] = 0;
            S[i][j] = 0;
        }
    }

    int xi, yi;
    for (int i=1; i<=N; i++){
        cin >> xi >> yi;
        X[xi][yi] += 1;
    }

    cin >> Q;
    for (int i=1; i<=Q; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    // yoko
    for (int i=1; i<=1500; i++) {
        for (int j=1; j<=1500; j++) {
            S[i][j] = S[i][j-1] + X[i][j];
        }
    }

    // tate
    for (int i=1; i<=1500; i++) {
        for (int j=1; j<=1500; j++) {
            S[i][j] = S[i-1][j] + S[i][j];
        }
    }

    for (int i=1;i<=Q; i++) {
        cout << S[C[i]][D[i]] + S[A[i]-1][B[i]-1] - S[A[i]-1][D[i]] - S[C[i]][B[i]-1] << endl;
    }
    return 0;
}