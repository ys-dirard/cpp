#include <bits/stdc++.h>
using namespace std;

int N, L;
int a[200009];

int main(){
    cin >> N >> L;
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    int seated = 0;
    bool flg = true;
    int num2 = 0;
    for(int i=1;i<=N;i++){
        if(a[i]==1){
            seated++;
        }
        if(a[i]==2){
            if(seated >= L/2) flg = false;
            seated++;
            L--;
        }
    }
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}