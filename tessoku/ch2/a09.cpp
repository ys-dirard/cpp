#include <iostream>
using namespace std;

int main(){
    int H, W, N;
    long long Diff[1509][1509], S[1509][1509];
    long long A[100009], B[100009], C[100009], D[100009];

    cin >> H >> W;
    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    for (int i=0; i<=H; i++) {
        for (int j=0; j<=W; j++) {
            S[i][j] = 0;
            Diff[i][j] = 0;
        }
    }

    for (int i=1; i<=N; i++){
        Diff[A[i]][B[i]] += 1;
        Diff[C[i]+1][D[i]+1] += 1;
        Diff[A[i]][D[i]+1] -= 1;
        Diff[C[i]+1][B[i]] -= 1;
    }

    // yoko
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            S[i][j] = S[i][j-1] + Diff[i][j];
        }
    }

    // tate
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            S[i][j] = S[i-1][j] + S[i][j];
        }
    }

    for (int i=1;i<=H; i++) {
        for (int j=1; j<=W; j++) {
            cout << S[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}