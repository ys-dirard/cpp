#include <bits/stdc++.h>
using namespace std;

int N, X;
int D[109], L[109];

int main(){
    cin >> N >> X;
    for(int i=1;i<=N;i++){
        cin >> L[i];
        D[i] = (1<<30);
    }
    
    D[1] = 0;
    for(int i=2;i<=N+1;i++){
        D[i] = D[i-1] + L[i-1];
    }
    int num = upper_bound(D+1, D+N+2,X) - D - 1;
    cout << num << endl;
    return 0;
}