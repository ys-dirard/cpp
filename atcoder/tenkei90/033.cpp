#include <bits/stdc++.h>
using namespace std;

int H, W;

int main(){
    cin >> H >> W;

    int r = (H + 1) / 2;
    int c = (W + 1) / 2;
    if(H==1 || W==1) cout << H*W << endl;
    else cout << (r * c) << endl;
    return 0;
}