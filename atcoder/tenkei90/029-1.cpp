#include <bits/stdc++.h>
using namespace std;

// 工夫しない気合ver.

int W, N;
int L[250009], R[250009];
int h[500009];

void init(){
    for(int i=1;i<=W;i++){
        h[i] = 0;
    }
}

int main(){
    cin >> W >> N;
    for(int i=1;i<=N;i++){
        cin >> L[i] >> R[i];
    }

    for(int i=1;i<=N;i++){
        int tmp = 0;
        for(int j=L[i];j<=R[i];j++){
            tmp = max(tmp, h[j]);
        }

        for(int j=L[i];j<=R[i];j++){
            h[j] = tmp + 1;
        }

        cout << tmp + 1 << endl;
    }
    return 0;
}