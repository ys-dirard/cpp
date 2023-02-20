#include <iostream>
using namespace std;

int main(){
    int N, D, A[100009];
    int L[100009], R[100009], P[100009], Q[100009];
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }
    cin >> D;
    for (int i=1; i<=D; i++) {
        cin >> L[i] >> R[i];
    }
    P[0] = 0;
    Q[N+1] = 0;

    for (int i=1; i<=N; i++) {
        P[i] = max(P[i-1], A[i]);
        Q[N-i+1] = max(Q[N-i+2], A[N-i+1]);
    }
    for (int i=1; i<=D; i++){
        cout << max(P[L[i]-1], Q[R[i]+1]) << endl;
    }
    return 0;
}