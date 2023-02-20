#include <bits/stdc++.h>
using namespace std;
#define ll long long

int L[200009], R[200009];

ll merge(int A[], int n, int l, int m, int r){
    int i, j, k;
    ll cnt = 0;
    int n1 = m - l;
    int n2 = r - m;
    for(i = 0;i<n1;i++) L[i] = A[l + i];
    for(i = 0;i<n2;i++) R[i] = A[m + i];
    L[n1] = R[n2] = 2000000000;

    i = j = 0;
    for(k = l; k < r; k++){
        if(L[i]<=R[j]){
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
            cnt += n1 - i;
        }
    }
    return cnt;
}

ll mergeSort(int A[], int n, int l, int r){
    int m;
    ll v1, v2, v3;
    if(l+1<r){
        m = (l+r)/2;
        v1 = mergeSort(A, n, l, m);
        v2 = mergeSort(A, n, m, r);
        v3 = merge(A, n, l, m, r);
        return v1+v2+v3;
    }else{
        return 0;
    }
}

int A[200009], n;

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> A[i];
    ll ans = mergeSort(A, n, 0, n);
    cout << ans << endl;
    return 0;
}