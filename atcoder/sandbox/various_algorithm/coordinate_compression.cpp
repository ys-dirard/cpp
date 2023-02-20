#include <bits/stdc++.h>
using namespace std;

// 工夫しない気合ver.

int W, N;
vector<int> L(250009), R(250009), LR(500009); // {L1, R1, L2, R2, ...}
int h[500009];

void init(){
    for(int i=1;i<=W;i++){
        h[i] = 0;
    }
}

// 座標圧縮(1D), V: 圧縮したい配列 (1-origin)
vector<int> coordinate_compression(vector<int> &V){
    // step1. copy
    vector<int> A = V;
    // step2. sort
    sort(A.begin(), A.end());
    // step3. Aから重複を削除
    A.erase(unique(A.begin(), A.end()), A.end());
    // step4. 座標圧縮した座標cmpを求める
    vector<int> cmp(V.size()+1);
    for(int i=1;i<=V.size();i++){
        cmp[i] = lower_bound(A.begin(), A.end(), V[i]) - A.begin();
    }
    return cmp;
}


int main(){
    cin >> W >> N;
    for(int i=1;i<=N;i++){
        cin >> L[i] >> R[i];
        LR[2*i-1] = L[i];
        LR[2*i] = R[i];
    }

    vector<int> cmp = coordinate_compression(LR);

    for(int i=1;i<=N;i++){
        int tmp = 0;
        for(int j=cmp[2*i-1];j<=cmp[2*i];j++){
            tmp = max(tmp, h[j]);
        }

        for(int j=cmp[2*i-1];j<=cmp[2*i];j++){
            h[j] = tmp + 1;
        }

        cout << tmp + 1 << endl;
    }
    return 0;
}