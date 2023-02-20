#include <bits/stdc++.h>
using namespace std;

int H, W;
int rs, cs, rt, ct;
char S[1009][1009];
int turn[1009][1009][4];
const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, -1, 0, 1};
struct state {
	int x, y, dir;
};
// deque<state> q; // (r, c, type), type:0→, 1↑, 2←, 3↓

int main(){
    cin.tie(0);
	ios_base::sync_with_stdio(false);
    cin >> H >> W >> rs >> cs >> rt >> ct;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> S[i][j];
            for(int k=0;k<4;k++) turn[i][j][k] = (1<<30);
        }
    }

    deque<state> q; // (r, c, type), type:0→, 1↑, 2←, 3↓
    turn[rs][cs][0] = turn[rs][cs][1] = turn[rs][cs][2] = turn[rs][cs][3] = 0;
    for(int i=0;i<4;i++){
        bool in_area = (rs+dr[i] >=1) && (rs+dr[i] <=H) && (cs+dc[i] >=1) && (cs+dc[i] <=W);
        if(in_area && S[rs+dr[i]][cs+dc[i]] != '#'){
            q.push_back({rs+dr[i], cs+dc[i], i});
            turn[rs+dr[i]][cs+dc[i]][i] = 0;
        }
    }
    
    while(!q.empty()){
        state pos = q.front();
        q.pop_front();
        int r = pos.x;
        int c = pos.y;
        int t = pos.dir;
        // cout << "r: " << r << ", c: " << c << ", t: " << t << endl;

        for(int i=0;i<4;i++){
            bool in_area = (r+dr[i] >=1) && (r+dr[i] <=H) && (c+dc[i] >=1) && (c+dc[i] <=W);
            // cout << "in_area: " << in_area << endl;
            if(in_area && S[r+dr[i]][c+dc[i]] != '#'){
                if(turn[r+dr[i]][c+dc[i]][i] > (turn[r][c][t] + !(t == i))){
                    // cout << "true" << endl;
                    turn[r+dr[i]][c+dc[i]][i] = (turn[r][c][t] + !(t == i));
                    if(t == i) q.push_front({r+dr[i], c+dc[i], i});
                    else q.push_back({r+dr[i], c+dc[i], i});
                }
            }
        }
    }

    // for(int i=1;i<=H;i++){
    //     for(int j=1;j<=W;j++){
    //         // cout << S[i][j] << " ";
    //         cout << turn[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = (1<<30);
    for(int i=0;i<4;i++){
        ans = min(ans, turn[rt][ct][i]);
    }
    cout << ans << endl;
    return 0;
}