#include <bits/stdc++.h>
using namespace std;

int n;
int A[2000009], B[2000009], C[2000009];
int k = 10000;

void countingSort(int A[], int* B, int k){
    for(int i=0;i<=k;i++) C[i] = 0;

    for(int j=1;j<=n;j++) C[A[j]]++;

    for(int i=1;i<=k;i++) C[i] = C[i] + C[i-1];

    for(int j=n;j>=1;j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> A[i];

    countingSort(A, B, k);
    // for(int i=0;i<=k;i++) C[i] = 0;

    // for(int j=1;j<=n;j++) C[A[j]]++;

    // for(int i=1;i<=k;i++) C[i] = C[i] + C[i-1];

    // for(int j=n;j>=1;j--){
    //     B[C[A[j]]] = A[j];
    //     C[A[j]]--;
    // }

    for(int i=1;i<=n;i++){
        if(i>1) cout << " ";
        cout << B[i];
    }
    cout << endl;
    return 0;
}