#include <bits/stdc++.h>
using namespace std;

int N, Q, C[100009], P[100009], L[100009], R[100009];
int p1[100009], p2[100009];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> C[i] >> P[i];
    cin >> Q;
    for(int i=1;i<=Q;i++) cin >> L[i] >> R[i];
    
    p1[0] = p2[0] = 0;
    for(int i=1;i<=N;i++){
        if(C[i]==1){
            p1[i] = p1[i-1] + P[i];
            p2[i] = p2[i-1];
        }else{
            p1[i] = p1[i-1];
            p2[i] = p2[i-1] + P[i];
        }
    }

    // for(int i=1;i<=N;i++){
    //     cout << p1[i] << " " << p2[i] << endl;
    // }
    for(int i=1;i<=Q;i++){
        cout << (p1[R[i]] - p1[L[i]-1]) << " " << (p2[R[i]] - p2[L[i]-1]) << endl;
    }
    return 0;
}