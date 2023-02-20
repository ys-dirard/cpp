#include <iostream>
using namespace std;

int main(){
    int N;
    long long Diff[1509][1509], S[1509][1509];
    long long A[100009], B[100009], C[100009], D[100009];

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    for (int i=0; i<=1500; i++) {
        for (int j=0; j<=1500; j++) {
            S[i][j] = 0;
            Diff[i][j] = 0;
        }
    }

    for (int i=1; i<=N; i++){
        Diff[A[i]][B[i]] += 1;
        Diff[C[i]][D[i]] += 1;
        Diff[A[i]][D[i]] -= 1;
        Diff[C[i]][B[i]] -= 1;
    }

    // yoko
    for (int i=0; i<=1500; i++) {
        for (int j=0; j<=1500; j++) {
            S[i][j] = S[i][j-1] + Diff[i][j];
        }
    }

    // tate
    for (int i=0; i<=1500; i++) {
        for (int j=0; j<=1500; j++) {
            S[i][j] = S[i-1][j] + S[i][j];
        }
    }

    long long area = 0;
    for (int i=0;i<=1500; i++) {
        for (int j=0; j<=1500; j++) {
            if (S[i][j] > 0) area++;
        }
    }
    cout << area << endl;
    return 0;
}