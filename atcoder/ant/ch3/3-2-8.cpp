#include <bits/stdc++.h>
using namespace std;

// 領域の個数

// WxHの格子状にN本の垂直または水平な
// 幅１の直線が引かれています
// 格子は線によって何個の領域に
// 分かれていますか

// 領域ごとにdfsを行い領域数をカウント
// しかし、制約的にTLE & MLE
// 座標圧縮を行う
// その前後と変化が起きない行、列を
// 削除しても領域の個数は変わらない
// →配列には線の端点のある行・列
// 　およびその前後の行・列があればよい
// たかだか6N*6Nの配列で済む！

// 制約
// 1<=W,H<=1000000
// 1<=N<=500
 
// input
// W=10, H=10, N=5
// X1={1,1,4,9,10}
// X2={6,10,4,9,10}
// Y1={4,8,1,1,6}
// Y2={4,8,10,5,10}
// それぞれ、i番目の要素は始点、終点を表す
// w->x, h->y
// output
// 6

int W, H, N;
int X1[509], X2[509], Y1[509], Y2[509];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// 塗りつぶし用
bool fld[3009][3009];

// x1, x2を座標圧縮し、座標圧縮した際の幅を返す
int compress(int *x1, int *x2, int w){
    vector<int> xs;

    for(int i=0;i<N;i++){
        for(int d=-1;d<=1;d++){
            int tx1 = x1[i] + d;
            int tx2 = x2[i] + d;
            if(1<=tx1 && tx1<=w) xs.push_back(tx1);
            if(1<=tx2 && tx2<=w) xs.push_back(tx2);
        }
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    for(int i=0;i<N;i++){
        x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }

    return xs.size();
}

int solve(){
    // 座標圧縮
    W = compress(X1, X2, W);
    H = compress(Y1, Y2, H);

    // 線のある部分を塗りつぶし
    memset(fld, 0, sizeof(fld));
    for(int i=0;i<N;i++){
        for(int y=Y1[i];y<=Y2[i];y++){
            for(int x=X1[i];x<=X2[i];x++){
                fld[y][x] = true;
            }
        }
    }

    // 領域を数える
    int ans = 0;
    for(int y=0;y<H;y++){
        for(int x=0;x<W;x++){
            if(fld[y][x]) continue;
            ans++;

            // BFS
            queue<pair<int, int>> q;
            q.push({x, y});
            while(!q.empty()){
                int sx = q.front().first;
                int sy = q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int tx = sx + dx[i];
                    int ty = sy + dy[i];
                    if(tx < 0 || W <= tx || ty < 0 || H <= ty) continue;
                    if(fld[ty][tx]) continue;

                    q.push({tx, ty});
                    fld[ty][tx] = true;
                }
            }
        }
    }

    return ans;
}

int main(){
    cin >> W >> H >> N;
    for(int i=0;i<N;i++) cin >> X1[i];
    for(int i=0;i<N;i++) cin >> X2[i];
    for(int i=0;i<N;i++) cin >> Y1[i];
    for(int i=0;i<N;i++) cin >> Y2[i];

    int ans = solve();
    cout << ans << endl;
    return 0;
}