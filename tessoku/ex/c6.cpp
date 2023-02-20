#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> g[109];
    for(int i=1;i<=N;i++){
        if(i==1){
            g[i].push_back(N);
        }else{
            g[i].push_back(i-1);
        }
    }

    cout << N << endl;
    for(int i=1;i<=N;i++){
        cout << i << " " << g[i][0] << endl;
    }
    return 0;
}