#include <bits/stdc++.h>
using namespace std;

int H, W;
int P[10][10009];

int d2b(int i){
    int ans = 0;
    while(i>0){
        if(i & 1) ans++;
        i >>= 1;
    }
    return ans;
}

int get_result(int d){
    vector<int> cnt(H*W+1, 0);
    int start = 0;
    for(int i=0;i<H;i++){
        if(d & (1<<i)){
            start = i;
            break;
        }
    }

    for(int j=0;j<W;j++){
        bool flg = true;
        for(int i=0;i<H;i++){
            if(d & (1<<i)){
                if(P[i][j] != P[start][j]) flg = false;
            }
        }
        if(flg){
            cnt[P[start][j]]++;
        }
    }

    int ans = 0;
    for(int i=1;i<=H*W;i++){
        // cout << cnt[i] << endl;
        ans = max(ans, cnt[i]);
    }
    // cout << "ans: " << ans << endl;
    // cout << "return: " << ans*d2b(d) << endl;
    return ans * d2b(d);
}

int main(){
    cin >> H >> W;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> P[i][j];
        }
    }

    int ans = 0;
    for(int i=1;i<(1<<H);i++){
        // cout << "---------------------" << endl;
        ans = max(ans, get_result(i));
    }
    cout << ans << endl;
    return 0;
}