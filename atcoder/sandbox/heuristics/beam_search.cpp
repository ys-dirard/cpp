#include <bits/stdc++.h>
using namespace std;

struct state{
    int score; // 暫定スコア
    int X[29]; // 現在の配列Xの値
    char lastMove; // 最後の動き'A' or 'B'
    int lastPos; // i-1手目時点では第何位であったか？
};

bool operator>(const state s1, const state s2){
    return s1.score > s2.score;
}

int N = 20, T = 100, P[109], Q[109], R[109];
int X[29];
int numState[109]; // i手目時点での状態数(必ずビーム幅以下になる)
state beam[109][10009]; // i手目j番目の状態
int width = 10000;

void beam_search(){
    // 0手目の状態の設定
    // 0手目はX=[0, 0, ..., 0]のみなのでnumState[0] = 1
    numState[0] = 1;
    beam[0][0].score = 0;
    for(int i=1;i<=N;i++) beam[0][0].X[i] = X[i];

    // beam search
    for(int i=1;i<=T;i++){
        vector<state> candidate;
        for(int j=0;j<numState[i-1];j++){
            // A
            state sa = beam[i-1][j];
            sa.lastMove = 'A';
            sa.lastPos = j;
            sa.X[P[i]] += 1;
            sa.X[Q[i]] += 1;
            sa.X[R[i]] += 1;
            for(int k=1;k<=N;k++){
                if(sa.X[k]==0) sa.score += 1;
            }

            // B
            state sb = beam[i-1][j];
            sb.lastMove = 'B';
            sb.lastPos = j;
            sb.X[P[i]] -= 1;
            sb.X[Q[i]] -= 1;
            sb.X[R[i]] -= 1;
            for(int k=1;k<=N;k++){
                if(sb.X[k]==0) sb.score += 1;
            }

            // 情報に追加
            candidate.push_back(sa);
            candidate.push_back(sb);
        }

        // sortしてbeam[i]の結果を計算
        sort(candidate.begin(), candidate.end(), greater<state>());
        numState[i] = min((int)candidate.size(), width);
        for(int j=0;j<numState[i];j++){
            beam[i][j] = candidate[j];
        }
    }
}

vector<char> get_actions(){
    vector<char> moves;
    int currentPlace = 0;
    for(int i=T;i>=1;i--){
        moves.push_back(beam[i][currentPlace].lastMove);
        currentPlace = beam[i][currentPlace].lastPos;
    }
    reverse(moves.begin(), moves.end());
    return moves;
}

int main(){
    cin >> T;
    for(int i=1;i<=T;i++){
        cin >> P[i] >> Q[i] >> R[i];
    }

    beam_search();
    vector<char> moves = get_actions();

    for(int i=0;i<moves.size();i++){
        cout << moves[i] << endl;
    }
    return 0;
}