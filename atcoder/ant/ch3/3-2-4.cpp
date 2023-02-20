#include <bits/stdc++.h>
using namespace std;

// Fliptile (POJ No.3279)

// MxNのマス目がある
// 各マスは裏返すことができ、
// 表は白、裏は黒である
// ただし、マス目をひっくり返すときは
// 縦横隣接するマスもひっくり返す
// 全部白にするための最短手数の方法を求める
// 複数ある場合は辞書順最小のものを出力する
// また、不可能な場合はImpossibleを出力する

// input
// M=4, N=4
// 1 0 0 1
// 0 1 1 0
// 0 1 1 0
// 1 0 0 1
// (0が白、1が黒)
// output
// 0 0 0 0
// 1 0 0 1
// 1 0 0 1
// 0 0 0 0

// 左上から考えればよい気もするが、
// 左上を反転させつ方法は一意ではない
// しかし、１行目の反転方法を決めれば
// ２行目以降の反転方法も一意に決まる
// O(MN2^N)

const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 1};

int M, N;
int tile[20][20];

int opt[20][20]; // 最適解保存用
int flip[20][20]; // 作業用

// (x, y)の色を調べる
int get(int x, int y){
    int c = tile[x][y];

    for(int d=0;d<5;d++){
        int x2 = x + dx[d];
        int y2 = y + dy[d];

        if(0 <= x2 && x2 < M && 0 <= y2 && y2 < N){
            c += flip[x2][y2];
        }
    }
    return c % 2;
}

// 1行目を決めた場合の最小操作回数を求める
// 解が存在しなければ-1
int calc(){
    // 2行目からのひっくり返し方を求める
    for(int i=1;i<M;i++){
        for(int j=0;j<N;j++){
            if(get(i-1, j) != 0){
                // (i-1, j)が黒ならこのマスをひっくり返すしかない
                flip[i][j] = 1;
            }
        }
    }

    // 最後の行が全部白かチェック
    for(int j=0;j<N;j++){
        if(get(M-1, j) != 0){
            return -1; // 解無し
        }
    }

    // 反転回数をカウント
    int res = 0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            res += flip[i][j];
        }
    }
    return res;
}

void solve(){
    int res = -1;

    // 1行目を辞書順で全通り試す
    for(int i=0;i<(1<<N);i++){
        memset(flip, 0, sizeof(flip));
        for(int j=0;j<N;j++){
            flip[0][N - j - 1] = (i>>j) & 1;
        }

        int num = calc();
        if(num >= 0 && (res < 0 || res > num)){
            res = num;
            memcpy(opt, flip, sizeof(flip));
        }
    }

    if(res < 0){
        // 解無し
        cout << "IMPOSSIBLE" << endl;
    }else{
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                cout << opt[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main(){
    cin >> M >> N;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin >> tile[i][j];
        }
    }

    solve();
    return 0;
}