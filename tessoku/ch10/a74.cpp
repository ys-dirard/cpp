#include <bits/stdc++.h>
using namespace std;

int N;
int P[109][109], X[109], Y[109];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> P[i][j];
            if(P[i][j]>0){
                X[i] = P[i][j];
                Y[j] = P[i][j];
            }
        }
    }

    int inversion_x = 0, inversion_y = 0;
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(X[i]>X[j]) inversion_x++;
            if(Y[i]>Y[j]) inversion_y++;
        }
    } 
    cout << inversion_x + inversion_y << endl;
    return 0;
}