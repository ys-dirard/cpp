#include <bits/stdc++.h>
using namespace std;

int H, W, K;
char c[19][109], d[19][109];

void change_row(int i){
    for(int j=1;j<=W;j++) d[i][j] = '#';
}

int count_white_col(int j){
    int cnt = 0;
    for(int i=1;i<=H;i++){
        if(d[i][j]=='.') cnt++; 
    }
    return cnt;
}

int count_black_all(){
    int cnt = 0;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(d[i][j]=='#') cnt++;
        }
    }
    return cnt;
}

void reset(){
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++) d[i][j] = c[i][j];
    }
}

int main(){
    cin >> H >> W >> K;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> c[i][j];
        }
    }

    int ans = 0;
    for(int i=0;i<(1<<H);i++){
        int num_i = 0;
        int cap[109];
        reset();
        for(int j=1;j<=H;j++){
            if((i / (1<<(j-1))) & 1){
                num_i++;
                change_row(j);
            }
        }
        if(num_i > K) continue;

        int tmp = count_black_all();
        for(int j=1;j<=W;j++) cap[j] = count_white_col(j);
        sort(cap+1, cap+W+1, greater<int>());
        for(int j=1;j<=(K-num_i);j++){
            tmp += cap[j];
        }

        ans = max(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}