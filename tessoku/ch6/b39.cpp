#include <bits/stdc++.h>
using namespace std;

int N, D;
long long X[200009], Y[200009];
vector<bool> used(200009, false);

int main(){
    cin >> N >> D;
    for (int i=1; i<=N; i++){
        cin >> X[i] >> Y[i];
    }

    long long ans = 0;
    for(int i=1; i<=D;i++){
        long long m = 0;
        int  max_index = -1;
        for (int j=1;j<=N;j++){
            if (!used[j] && i>=X[j] && m<Y[j]) {
                m = Y[j];
                max_index = j;
            }
        }
        if(max_index !=-1){
            used[max_index] = true;
            ans += m;
        }
    }
    cout << ans << endl;
    return 0;
}