#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, P, K;
ll A[49][49];
ll dist[49][49];

void init(ll X){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            dist[i][j] =  (A[i][j] >= 0) ? A[i][j] : X;
        }
    }
}

int main(){
    cin >> N >> P >> K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> A[i][j];
        }
    }

    // K個以上となるなかで最小のものは？
    // 値が大きくなれば個数は小さくなる
    // val[K] - val[K+1]が答え
    ll l=0, r = (1LL<<60), m;
    ll cnt = 0;
    while(r-l>0){
        m = (l+r+1)/2;
        init(m);

        for(int k=1;k<=N;k++){
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        cnt = 0;
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                if(dist[i][j] <= P) cnt++;
            }
        }
        if(cnt >= K){
            l = m;
        }else{
            r = m-1;
        }
    }
    ll val1 = r;

    // K+1個以上となるなかで最小のものは？
    K++;
    l=0, r = (1LL<<60), m;
    cnt = 0;
    while(r-l>0){
        m = (l+r+1)/2;
        init(m);

        for(int k=1;k<=N;k++){
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        cnt = 0;
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                if(dist[i][j] <= P) cnt++;
            }
        }
        if(cnt >= K){
            l = m;
        }else{
            r = m-1;
        }
    }
    ll val2 = r;

    // init(5);
    // // for(int i=1;i<=N;i++){
    // //     for(int j=1;j<=N;j++){
    // //         cout << dist[i][j] << " ";
    // //     }
    // //     cout << endl;
    // // }
    // for(int k=1;k<=N;k++){
    //     for(int i=1;i<=N;i++){
    //         for(int j=1;j<=N;j++){
    //             dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    //         }
    //     }
    // }
    // ll cnt = 0;
    // for(int i=1;i<N;i++){
    //     for(int j=i+1;j<=N;j++){
    //         if(dist[i][j] <= P) cnt++;
    //     }
    // }

    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << val1 << " " << val2 << endl;
    
    if(val2 >= (1LL<<55)) cout << 0 << endl;
    else if(val1 >= (1LL<<55)) cout << "Infinity" << endl;
    else cout << val1 - val2 << endl;
    return 0;
}