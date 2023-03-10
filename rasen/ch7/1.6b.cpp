#include <bits/stdc++.h>
using namespace std;

int n, A[100009];

int partition(int A[], int p, int r){
    int x = A[r];
    int i = p - 1;

    for(int j=p;j<r;j++){
        if(A[j]<=x){
            i++;
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    int tmp2 = A[i+1];
    A[i+1]= A[r];
    A[r] = tmp2;
    return i+1;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> A[i];

    int q = partition(A, 0, n-1);
    for(int i=0;i<n;i++){
        if(i>0) cout << " ";
        if(i==q) cout << "[";
        cout << A[i];
        if(i==q) cout << "]";
    }
    cout << endl;
    return 0;
}