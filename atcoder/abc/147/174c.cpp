#include <bits/stdc++.h>
using namespace std;

bool amari[1000006];

int main(){
    int K;
    cin >> K;
    int tmp = 0;
    int i = 0;
    
    while(1){
        i++;
        tmp = tmp * 10 + 7;
        tmp %= K;
        if(tmp == 0){
            cout << i << endl;
            return 0;
        }
        if(amari[tmp]){
            cout << -1 << endl;
            return 0;
        }else{
            amari[tmp] = true;
        }
    }
    return 0;
}