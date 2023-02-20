#include <bits/stdc++.h>
using namespace std;

int M, N;
int A[200009];
int fail[200009];

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++) cin >> A[i];

    for(int i=1;i<=M;i++) {
        fail[A[i]] += 1;
    }
    for(int i=1;i<=N;i++){
        cout << M - fail[i] << endl;
    }
    return 0;
}