#include <bits/stdc++.h>
using namespace std;

int N;
int A[10000009];
const int wari = 1000000007;

int main(){
    cin >> N;
    A[1] = A[2] = 1;

    for (int i=3; i<=N; i++){
        A[i] = (A[i-1] + A[i-2]) % wari;
    }
    cout << A[N] << endl;
    return 0;
}