#include <bits/stdc++.h>
using namespace std;

int N, Q, A[509][509];
int t, x, y;
int T[509];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> A[i][j];
        }
    }
    for(int i=1;i<=N;i++) T[i] = i;

    cin >> Q;
    for(int i=1;i<=Q;i++){
        cin >> t;
        cin >> x >> y;
        if(t == 1){
            int tmp = T[x];
            T[x] = T[y];
            T[y] = tmp;
        } else {
            cout << A[T[x]][y] << endl;
        }
    }
    return 0;
}