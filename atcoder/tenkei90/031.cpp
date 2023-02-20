#include <bits/stdc++.h>
using namespace std;

int N;
int W[100009], B[100009];
int g[59][1350]; // g[i][j]: 白石i個、青石j個の状態のgrundy数

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> W[i];
    for(int i=1;i<=N;i++) cin >> B[i];
    
    g[0][0] = g[0][1] = 0;
    for(int i=0;i<=50;i++){
        int s = 50 + (1+i)*i/2;
        for(int j=0;j<=s;j++){
            int k_max=j/2;
            vector<bool> tmp_g(1350, false);
            for(int k=1;k<=k_max;k++){
                tmp_g[g[i][j-k]] = true;
            }
            if(i>0) tmp_g[g[i-1][j+i]] = true;

            int min_g;
            for(int k=0;k<1300;k++){
                if(tmp_g[k] == false){
                    min_g = k;
                    break;
                }
            }
            g[i][j] = min_g;
        }
    }

    int xr = 0;
    for(int i=1;i<=N;i++){
        xr ^= g[W[i]][B[i]];
    }
    if(xr) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}