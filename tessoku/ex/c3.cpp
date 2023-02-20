#include <bits/stdc++.h>
using namespace std;

int D, X, A[200009], Q, S[200009], T[200009];
int kabuka[200009];

int main(){
    cin >> D >> X;
    kabuka[1] = X;
    for(int i=2;i<=D;i++){
        cin >> A[i];
        kabuka[i] = kabuka[i-1] + A[i];
    }
    cin >> Q;
    for(int i=1;i<=Q;i++){
        cin >> S[i] >> T[i];
        if(kabuka[S[i]] > kabuka[T[i]]) cout << S[i] << endl;
        else if(kabuka[S[i]] < kabuka[T[i]]) cout << T[i] << endl;
        else cout << "Same" << endl;
    }
    return 0;
}