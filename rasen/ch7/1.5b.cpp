#include <bits/stdc++.h>
using namespace std;

int n, S[500009];
const int INF = (1 << 30);
int cnt = 0;

void merge(int* A, int left, int mid, int right){
    const int n1 = mid - left;
    const int n2 = right - mid;
    vector<int> L(n1+1), R(n2+1);
    for(int i=0;i<n1;i++) L[i] = A[left + i];
    for(int i=0;i<n2;i++) R[i] = A[mid + i];
    L[n1] = R[n2] = INF;
    int i = 0, j = 0;
    for(int k=left;k<right;k++){
        cnt++;
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int* A, int left, int right){
    if(left + 1 < right){
        int mid = (left+right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> S[i];

    mergeSort(S, 0, n);
    for(int i= 0;i<n;i++){
        if(i!=0) cout << " ";
        cout << S[i];
    }
    cout << endl << cnt << endl;
    return 0;
}