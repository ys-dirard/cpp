#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[200009], B[200009];
int p[5009][5009], S[5009][5009];

int main(){
    cin >> N >> K;
    for(int x=0;x<=5000;x++){
        for(int y=0;y<=5000;y++){
            p[x][y] = 0;
            S[x][y] = 0;
        }
    }
    for(int i=1;i<=N;i++){
        cin >> A[i] >> B[i];
        p[A[i]][B[i]] += 1;
    }

    for(int x=0;x<=5000;x++){
        for(int y=1;y<=5000;y++){
            S[x][y] = S[x][y-1] + p[x][y];
        }
    }

    for(int x=1;x<=5000;x++){
        for(int y=0;y<=5000;y++){
            S[x][y] = S[x-1][y] + S[x][y];
        }
    }

    int ans = 0;
    for(int x=1;x<=5000-K;x++){
        for(int y=1;y<=5000-K;y++){
            int tmp = S[x+K][y+K] - S[x-1][y+K] - S[x+K][y-1] + S[x-1][y-1];
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
    return 0;
}