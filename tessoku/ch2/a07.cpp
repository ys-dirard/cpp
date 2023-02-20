#include <iostream>
using namespace std;

int main(){
    long long D, N, B[100009], S[100009];
    cin >> D >> N;
    for (int i=0; i<=N; i++) B[i] = 0;

    long long l, r;
    for (int i=1; i<=N; i++){
        cin >> l >> r;
        B[l] += 1;
        B[r + 1] -= 1;
    }

    S[0] = 0;
    for (int i=1; i<=D; i++) {
        S[i] = S[i-1] + B[i];
    }
    for (int i=1; i<=D; i++) {
        cout << S[i] << endl;
    }
    return 0;
}