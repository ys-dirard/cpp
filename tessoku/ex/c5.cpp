#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
    cin >> N;
    string ans = "4444444444";
    for(int i=1;i<=10;i++){
        if(((N-1) /(1 << (i-1))) % 2 == 1){
            ans[10 - i] = '7';
        }
    }
    cout << ans << endl;
    return 0;
}