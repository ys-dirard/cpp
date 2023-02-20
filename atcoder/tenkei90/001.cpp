#include <bits/stdc++.h>
using namespace std;

int N, L, K;
int A[100009];

int main(){
    cin >> N >> L >> K;
    for(int i=1;i<=N;i++){
        cin >> A[i];
    }

    int l = 1, r = 1000000000;
    while(r-l>0){
        int m = (l+r+1)/2;
        // cout << "l: " << l << ", r: " << r << ", m: " << m << endl;
        int n_piece = 0;
        int pre_place = 0;
        for(int i=1;i<=N;i++){
            if(A[i]-pre_place>=m){
                n_piece++;
                pre_place = A[i];
            }
        }
        if(L-pre_place<m) n_piece--;
        // cout << "n: " << n_piece << endl;
        if(n_piece >= K){
            l = m;
        }else{
            r = m-1;
        }
    }
    cout << l << endl;
    return 0;
}