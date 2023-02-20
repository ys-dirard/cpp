#include <bits/stdc++.h>
using namespace std;

// 局所探索法(山登り法)

// 解を少しずつ改善することで最終的に質の高い解を生成するアルゴリズム

// step1: 初期解を適当に生成する
// step2: (近傍内で)小さな変更を行い、スコアが良くなれば採用することを繰り返す

// 近傍探索は巡回セールスマン問題なら現在の解に対して特定の都市区間(ex. [5. 7])に対する
// 訪れる順番を逆にする(1->2->3->4->7->6->5-?...)等が考えられる

// 局所探索法は局所解にはまり抜け出せないことがある…。

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

    int n_loop = 2e5;
    // d = 0.0;
    d = dist_sum(v, p);
    // for(int i=0;i<N;i++) d += dist(p[v[i]], p[v[i+1]]);
    for(int i=0;i<n_loop;i++){
        vector<int> tmp = v;
        int a = randint(1, N-1);
        int b = randint(1, N-1);
        if(a>b) swap(a, b);
        else if(a==b) continue;

        reverse(tmp.begin()+a, tmp.begin()+b+1);
        
        double dist_tmp = dist_sum(tmp, p);
        if(dist_tmp < d){
            d = dist_tmp;
            reverse(v.begin()+a, v.begin()+b+1);
        }
    }

    for(int i=0;i<N+1;i++) cout << v[i] << endl;
    return 0;
}