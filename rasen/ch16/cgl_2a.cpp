#include <bits/stdc++.h>
using namespace std;

int n, x[4], y[4];

int check_state(int *x, int *y){
    pair<int, int> v1, v2;
    v1 = {x[1]-x[0], y[1]-y[0]};
    v2 = {x[3]-x[2], y[3]-y[2]};

    if((v1.first*v2.first + v1.second*v2.second) == 0){
        return 1;
    }else if(v1.first*v2.second - v1.second*v2.first == 0){
        return 2;
    }else{
        return 0;
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            cin >> x[j] >> y[j];
        }
        cout << check_state(x, y) << endl;
    }
}