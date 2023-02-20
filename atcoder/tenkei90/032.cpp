#include <bits/stdc++.h>
using namespace std;

int N, A[11][11];
int M, X[50], Y[50];
set<int> coop[11];
vector<int> perm;

bool check(){
    bool flg = true;
    for(int i=0;i<N-1;i++){
        if(coop[perm[i]].find(perm[i+1]) != coop[perm[i]].end()){
            flg = false;
        }
    }
    return flg;
}

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> A[i][j];
        }
    }
    cin >> M;
    for(int i=1;i<=M;i++){
        cin >> X[i] >> Y[i];
        coop[X[i]].insert(Y[i]);
        coop[Y[i]].insert(X[i]);
    }
    for(int i=1;i<=N;i++) perm.push_back(i);

    int ans = (1<<30);
    do{
        if(check()){
            int tmp = 0;
            for(int i=1;i<=N;i++){
                tmp += A[perm[i-1]][i];
            }
            ans = min(ans, tmp);
        }
    }while(next_permutation(perm.begin(), perm.end()));

    if(ans == (1<<30)) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}