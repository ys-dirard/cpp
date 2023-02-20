#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, bool> vis;
string s[1000005];
const int oprx[] = {0, 0, 1, -1}, opry[] = {1, -1, 0, 0};
int h, w, sx, sy;
void dfs(int x, int y, int prex, int prey)
{
    vis[{x, y}] = 1;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + oprx[i], ty = y + opry[i];
        if (tx >= 0 && tx < h && ty >= 0 && ty < w && s[tx][ty] != '#' && (tx != prex || ty != prey) && !vis[{tx, ty}])
        {
            if (tx == sx && ty == sy)
            {
                cout << "Yes\n";
                exit(0);
            }
            dfs(tx, ty, x, y);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == 'S')
            {
                sx = i;
                sy = j;
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int tx = sx + oprx[i], ty = sy + opry[i];
        if (tx >= 0 && tx < h && ty >= 0 && ty < w && s[tx][ty] == '.' && vis[{tx, ty}] == 0)
            dfs(tx, ty, sx, sy);
    }
    cout << "No\n";
}

// /* #region convenient */
// #include <bits/stdc++.h>
// #define rep(i,s,n) for(int i = s; i < n; i++)
// #define ll long long
// #define P pair<ll, ll>
// using namespace std;
// /* #endregion*/

// using namespace std;

// int H, W;
// char C[1000009];
// int start;
// int num[1000009];

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> H >> W;

//     for(int i=0;i<=H+1;i++){
//         for(int j=0;j<=W+1;j++){
//             int pos = (W+2)*i + j;
//             if(i==0 || i==H+1 || j==0 || j==W+1){
//                 C[pos] = '#';
//             }else{
//                 cin >> C[pos];
//             }
//             if(C[pos]=='S'){
//                 start = pos;
//                 num[start] = -1;
//             }else if(C[pos]=='.'){
//                 num[pos] = 0;
//             }else{
//                 num[pos] = -1;
//             }
//         }
//     }
    
//     queue<int> bfs;
//     int cnt = 1;
//     if(num[start+1] == 0){
//         num[start+1] = cnt;
//         cnt++;
//         bfs.push(start+1);
//     }
//     if(num[start-1] == 0){
//         num[start-1] = cnt;
//         cnt++;
//         bfs.push(start-1);
//     }
//     if(num[start+W+2] == 0){
//         num[start+W+2] = cnt;
//         cnt++;
//         bfs.push(start+W+2);
//     }
//     if(num[start-W-2] == 0){
//         num[start-W-2] = cnt;
//         cnt++;
//         bfs.push(start-W-2);
//     }
    
//     bool flg = false;
//     while(!bfs.empty()){
//         int tmp = bfs.front();
//         bfs.pop();

//         if(num[tmp+1] == 0){
//             num[tmp+1] = num[tmp];
//             bfs.push(tmp+1);
//         }else if(num[tmp+1] > 0 && num[tmp] != num[tmp+1]){
//             flg = true;
//             break;
//         }
//         if(num[tmp-1] == 0){
//             num[tmp-1] = num[tmp];
//             bfs.push(tmp-1);
//         }else if(num[tmp-1] > 0 && num[tmp] != num[tmp-1]){
//             flg = true;
//             break;
//         }
//         if(num[tmp+W+2] == 0){
//             num[tmp+W+2] = num[tmp];
//             bfs.push(tmp+W+2);
//         }else if(num[tmp+W+2] > 0 && num[tmp] != num[tmp+W+2]){
//             flg = true;
//             break;
//         }
//         if(num[tmp-W-2] == 0){
//             num[tmp-W-2] = num[tmp];
//             bfs.push(tmp-W-2);
//         }else if(num[tmp-W-2] > 0 && num[tmp] != num[tmp-W-2]){
//             flg = true;
//             break;
//         }
//     }

//     if(flg) cout << "Yes" << endl;
//     else cout << "No" << endl;
//     return 0;
// }