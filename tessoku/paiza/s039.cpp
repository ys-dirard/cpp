#include <bits/stdc++.h>

#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>

using namespace std;

int H, W;
char s[509][509];
int v[509][509];
int vt[509][509];

int search_h(int s, int j){
    int ans = H+1;
    for(int k=s;k<=H;k++){
        if(vt[j][k]==1){
            ans = k;
            break;
        }
    }
    return ans;
}

int search_w(int s, int i){
    int ans = W+1;
    for(int k=s;k<=W;k++){
        if(v[i][k]==1){
            ans = k;
            break;
        }
    }
    return ans;
}

int main(){
    cin >> H >> W;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> s[i][j];
            if(s[i][j] == '#') v[i][j] = 1;
            else v[i][j] = 0;
        }
    }

    for(int j=1;j<=W;j++){
        for(int i=1;i<=H;i++){
            vt[j][i] = v[i][j];
        }
    }

    int ans = 0;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(v[i][j]==1) continue;
            // int h_wall_pos = lower_bound(vt[j]+i, vt[j]+H+1, 1) - vt[j];
            int h_wall_pos = search_h(i, j);
            
            int min_w = 1000;
            for(int ii=i;ii<h_wall_pos;ii++){
                // int w_wall_pos = lower_bound(v[ii]+j, v[ii]+W+1, 1) - v[ii];
                 int w_wall_pos = search_w(j, ii);
                // cout << "i: " << i << ", j: " << j << ", ii: " << ii << endl;
                // cout << "h_wall_pos: " << h_wall_pos << endl;
                // cout << "w_wall_pos: " << w_wall_pos << endl;
                min_w = min(min_w, w_wall_pos - j);
                // cout << "min_w: " << min_w << endl;
                if(ans < (i - ii + 1) * min_w){
                    // cout << "i: " << (i) << ", j: " << j << endl;
                    // cout << "h: " << (i - ii + 1) << ", w: " << min_w << endl;
                }
                ans = max(ans, (ii - i + 1) * min_w);
                // cout << "ans: " << ans << endl;
            }
        }
    }
    cout << ans << endl;

    ////////////////////////////////////////////////////////////////////
    // for(int i=1;i<=H;i++){
    //     int wall_pos = lower_bound(v[i]+1, v[i]+W+1, 1) - v[i];
    //     cout << wall_pos << endl;
    // }

    // for(int j=1;j<=W;j++){
    //     int wall_pos = lower_bound(vt[j]+1, vt[j]+H+1, 1) - vt[j];
    //     cout << wall_pos << endl;
    // }

    // for(int i=1;i<=H;i++){
    //     int wall_pos = 
    // }
    return 0;
}