#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[1009], B[1009];

int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> A[i];
    }
    for(int i=1;i<=N;i++){
        cin >> B[i];
    }

    int zure = 0;
    for(int i=1;i<=N;i++){
        zure += abs(A[i] - B[i]);
    }
    
    if(zure <= K && ((K % 2) == (zure % 2))) cout << "Yes" << endl;
    else cout << "No" << endl; 
    return 0;
}