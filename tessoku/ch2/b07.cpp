#include <iostream>
using namespace std;

int main(){
    long long T, N, B[500009], S[500009];
    cin >> T >> N;
    for (int i=0; i<=N; i++) B[i] = 0;

    long long l, r;
    for (int i=1; i<=N; i++){
        cin >> l >> r;
        B[l] += 1;
        B[r] -= 1;
    }

    S[0] = B[0];
    for (int i=1; i<T; i++) {
        S[i] = S[i-1] + B[i];
    }
    for (int i=0; i<T; i++) {
        cout << S[i] << endl;
    }
    return 0;
}