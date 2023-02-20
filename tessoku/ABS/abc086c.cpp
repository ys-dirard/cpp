#include <bits/stdc++.h>
using namespace std;

int N, t[100009], x[100009], y[100009];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> t[i] >> x[i] >> y[i];

    bool ans = true;
    for(int i=1;i<=N;i++){
        bool dist_flg = true, roop_flg = true, tmp = false;
        dist_flg = abs(x[i]-x[i-1])+abs(y[i]-y[i-1])<=(t[i]-t[i-1]);
        if(dist_flg){
            roop_flg = ((t[i]-t[i-1]) - (abs(x[i]-x[i-1])+abs(y[i]-y[i-1]))) % 2 == 0;
            if(roop_flg){
                tmp = true;
            }
        }
        ans = ans && tmp;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}