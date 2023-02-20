#include <bits/stdc++.h>
using namespace std;

// 焼きなまし法

// 解を少しずつ改善することで最終的に質の高い解を生成するアルゴリズム
// 局所探索法と違い結果が悪くなる時も変更を確率的に許すことにする(局所解から抜け出すことが目標)

// スコアの落差をΔとすると採用確率pは以下の式を使うことが多い, Δ->改善なら-, 改善しないなら+ の値をとる
// p = 1          (スコアが改善するとき)
//     exp(-Δ/T)  (スコアが悪化するとき)
// Tは温度と呼ばれ、Tが大きいほうが採用確率が大きくなる
// Tの気持ちとしては
// 序盤：いろいろ探索したいのでTは大きくする
// 終盤：より良い回を探索したいのでTは小さくする
// →iterationごとにTを調整する！

struct point{
    double x, y;
};

double dist(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

// [a, b]の整数をランダムに発生させる関数
// rand()は[0, RAND_MAX]からランダムに整数を返す
// rand()は乱数の質が悪いらしいのでXORシフトやメルセンヌ・ツイスタなどがよいらしい
int randint(int a, int b){
    return a + rand() % (b - a + 1);
}

double randdouble(){
    return 1.0 * rand() / RAND_MAX;
}

double get_adopt_prob(double prev_score, double new_score, double thermo){
    return min(1.0, exp(-(new_score - prev_score) / thermo));
}

double dist_sum(vector<int>& v, point* p){
    double d = 0.0;
    for(int i=0;i<v.size()-1;i++) d += dist(p[v[i]], p[v[i+1]]);
    return d;
}

int N;
double X[1009], Y[1009];
point p[1009];
bool visited[1009];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> X[i] >> Y[i];
        p[i] = {X[i], Y[i]};
    }

    // とりあえずgreedyで初期解を生成
    double d;
    int cnt = 1;
    int pos = 1;
    vector<int> v;
    v.push_back(1);
    while(cnt < N){
        d = (1<<30);
        int min_id = -1;
        for(int i=2;i<=N;i++){
            if(visited[i]) continue;
            if(dist(p[pos], p[i]) < d){
                d = dist(p[pos], p[i]);
                min_id = i;
            }
        }
        pos = min_id;
        visited[pos] = true;
        v.push_back(pos);
        cnt++;
    }
    v.push_back(1);

    // 焼きなまし開始
    int n_loop = 2e5;
    // d = 0.0;
    d = dist_sum(v, p);
    // for(int i=0;i<N;i++) d += dist(p[v[i]], p[v[i+1]]);
    double T_init = 30;
    double T_final = 2;
    for(int i=0;i<n_loop;i++){
        vector<int> tmp = v;
        double T = ((n_loop - i)*T_init + i*T_final) / n_loop;
        int a = randint(1, N-1);
        int b = randint(1, N-1);
        if(a>b) swap(a, b);
        else if(a==b) continue;

        reverse(tmp.begin()+a, tmp.begin()+b+1);
        
        double dist_tmp = dist_sum(tmp, p);
        double prob = min(1.0, exp(-(dist_tmp - d)/T));
        if(randdouble() < prob){
            d = dist_tmp;
            reverse(v.begin()+a, v.begin()+b+1);
        }
    }

    for(int i=0;i<N+1;i++) cout << v[i] << endl;
    return 0;
}