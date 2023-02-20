#include <bits/stdc++.h>
using namespace std;

int n, k, w[100009];
int S[100009];

int main(){
    S[0] = 0;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> w[i];
        S[i] = S[i-1]+w[i];
    }

    // trackの台数を二分探索
    int l=1, r=1000000000;
    int m;
    while(l<r){
        m = (l+r)/2;

        int* itr = S;
        int nk = 0;
        // cout << "l: " << l << ", r: " << r << endl;
        while(itr != (S+n)){
            // cout << "m: " << m << endl;
            int* pos = upper_bound(S,S+n+1,*itr+m);
            // cout << "pre pos: " << pos-S << endl;
            pos--;
            // if(pos == (S+n) && (S[n]-*itr > m || S[n]-*itr == 0)) break;
            if(pos - itr == 0){
                nk = 100000;
                break;
            }
            // cout << "pos: " << pos-S << endl;
            // cout << "S[n]-*itr: " << (S[n]-*itr) << endl;
            nk++;
            itr = pos;
        }
        // cout << "m: " << m << ", nk: " << nk << endl;
        if(nk>k){
            l = m+1;
        }else{
            r = m;
        }
        // cout << endl;
    }
    // cout << "l: " << l << ", r: " << r << endl;
    cout << r << endl;
    return 0;
}