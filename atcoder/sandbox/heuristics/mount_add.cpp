#include <bits/stdc++.h>
using namespace std;

int N = 100, Q = 1000, A[109][109], B[109][109];
int X[1009], Y[1009], H[1009];

// [a, b]の整数をランダムに発生させる関数
// rand()は[0, RAND_MAX]からランダムに整数を返す
// rand()は乱数の質が悪いらしいのでXORシフトやメルセンヌ・ツイスタなどがよいらしい
int randint(int a, int b){
    return a + rand() % (b - a + 1);
}

double randdouble(){
    return 1.0 * rand() / RAND_MAX;
}

int get_score(){
    int sum = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            sum += abs(A[i][j] - B[i][j]);
        }
    }
    return 200000000 - sum;
}

// X[t] = x, Y[t] = y, H[t] = h に変更する関数
void change(int t, int x, int y, int h){
    // 1. 配列Bに対して引き算
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            B[i][j] -= max(0, H[t] - abs(X[t] - j) - abs(Y[t] - i));
        }
    }

    // X[t], Y[t], H[t] の変更
    X[t] = x;
    Y[t] = y;
    H[t] = h;

    // 2. 配列Bに対して足し算
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            B[i][j] += max(0, H[t] - abs(X[t] - j) - abs(Y[t] - i));
        }
    }
}

void local_search(){
    int TIME_LIMIT = 5.95 * CLOCKS_PER_SEC; // 5.95秒, CLOCKS_PER_SEC: 1秒が何ミリ秒かを表す
    int current_score = get_score();
    int ti = clock();

    // start local search
    while(clock() - ti < TIME_LIMIT){
        int t = randint(1, Q);
        int old_x = X[t], new_x = X[t] + randint(-9, 9);
        int old_y = Y[t], new_y = Y[t] + randint(-9, 9);
        int old_h = H[t], new_h = H[t] + randint(-19, 19);
        if(new_x < 0 || new_x >= N) continue;
        if(new_y < 0 || new_y >= N) continue;
        if(new_h <= 0 || new_h > N) continue;

        // とりあえず変更してみる
        change(t, new_x, new_y, new_h);
        int new_score = get_score();

        // スコアに応じて採用or不採用
        double temp = 180.0 - 179.0 * (clock() - ti) / TIME_LIMIT;
        double prob = exp(min(0.0, 1.0 * (new_score - current_score) / temp));
        // 焼きなましver.
        if(randdouble() < prob) current_score = new_score;
        // local search ver.
        // if(current_score < new_score) current_score = new_score;
        else change(t, old_x, old_y, old_h);
    }
}

int main(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> A[i][j];
        }
    }

    // init
    for(int i=1;i<=Q;i++){
        X[i] = rand() % N;
        Y[i] = rand() % N;
        H[i] = 1;
        B[Y[i]][X[i]] += 1;
    }

    local_search();

    cout << Q << endl;
    for(int i=1;i<=Q;i++){
        cout << X[i] << " " << Y[i] << " " << H[i] << endl;
    }
    return 0;
}