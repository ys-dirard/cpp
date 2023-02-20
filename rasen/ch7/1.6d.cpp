#include <bits/stdc++.h>
using namespace std;

int n, w[1000];
int tmp[1000], tw[10009]; //tmp: sort用、tw: ｗがsort後どのいちにくるか？
int minw = 100000;

int solve(){
    int ans = 0;

    bool V[1000];
    for(int i=0;i<n;i++){
        tmp[i] = w[i];
        V[i] = false;
    }

    sort(tmp, tmp+n);
    for(int i=0;i<n;i++){
        tw[tmp[i]] = i;
    }

    for(int i=0;i<n;i++){
        if(V[i]) continue;

        int cur = i; // sort後の位置
        int S = 0;
        int m = 10000;
        int an = 0;

        int c = 0;
        while(true){ 
            V[cur] = true;
            an++;
            int v = w[cur]; // sort後の位置での値(探索サイクルの現在の値)、loopの前段の値を動かすためにここが邪魔
            m = min(m, v);
            S += v;
            cur = tw[v]; // 現在の値のソート後の位置
            if(V[cur]) break;
        }
        ans += min(S + (an - 2)*m, m + S + (an+1)*minw);
    }
    return ans;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> w[i];
        minw = min(minw, w[i]);
    }

    int ans = solve();
    cout << ans << endl;
    return 0;
}