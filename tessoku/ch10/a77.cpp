#include <bits/stdc++.h>
using namespace std;

long long N, L, K, A[100009];
long long S[100009];

int main(){
    cin >> N >> L >> K;
    A[0] = 0;
    for(int i=1;i<=N;i++){
        cin >> A[i];
    }

    int l=1, r=1000000000;
    while(r>l){
        long long m = (r+l+1)/2;
        long long kireme = 0, idx = 0;
        for(int i=1;i<=N;i++){
            if(A[i]-A[idx]>=m && L-A[i]>=m){
                kireme++;
                idx = i;
            }
        }
        if(kireme>=K){
            l = m;
        }else if(kireme<K){
            r = m-1;
        }
    }
    cout << l << endl;
    return 0;
}