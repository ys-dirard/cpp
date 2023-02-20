#include <bits/stdc++.h>
using namespace std;

// 2部グラフ、奇数長の閉路を持たない、最大マッチングが多項式時間で計算できる等の性質がある！
int N, A[100009], B[100009];
vector<int> g[100009];
vector<int> cls(100009, -1);
vector<int> cl[2];

int main(){
    cin >> N;
    for(int i=1;i<N;i++){
        cin >> A[i] >> B[i];
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
    }

    queue<int> q;
    q.push(1);
    cls[1] = 0;
    cl[0].push_back(1);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();

        for(int i=0;i<g[tmp].size();i++){
            int next = g[tmp][i];
            if(cls[next] == -1){
                cls[next] = 1 - cls[tmp];
                cl[1 - cls[tmp]].push_back(next);
                q.push(next);
            }
        }
    }
    int idx = 0;
    if(cl[0].size()<cl[1].size()) idx = 1;
    
    for(int i=0;i<N/2;i++){
        if(i) cout << " ";
        cout << cl[idx][i];
    }
    cout << endl;
    return 0;
}