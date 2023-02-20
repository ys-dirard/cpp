#include <bits/stdc++.h>
using namespace std;

int N;
int S[1009][1009];
int lx, rx, ly, ry;
const int A = 1001;

int main(){
    cin >> N;
    for(int i=0;i<=A;i++){
        for(int j=0;j<=A;j++){
            S[i][j] = 0;
        }
    }

    for(int i=1;i<=N;i++){
        cin >> lx >> ly >> rx >> ry;

        S[lx][ly]++;
        S[rx][ly]--;
        S[lx][ry]--;
        S[rx][ry]++;
    }

    for(int i=0;i<=A;i++){
        for(int j=1;j<=A;j++){
            S[i][j] = S[i][j-1] + S[i][j];
        }
    }
    for(int i=1;i<=A;i++){
        for(int j=0;j<=A;j++){
            S[i][j] = S[i-1][j] + S[i][j];
        }
    }

    // for(int i=1;i<=10;i++){
    //     for(int j=1;j<=10;j++){
    //         cout << S[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> ans(N+1, 0);
    for(int i=0;i<=A;i++){
        for(int j=0;j<=A;j++){
            if(S[i][j]>0) ans[S[i][j]]++;
        }
    }

    for(int i=1;i<=N;i++){
        cout << ans[i] << endl;
    }
    return 0;
}