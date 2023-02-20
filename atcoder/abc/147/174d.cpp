#include <bits/stdc++.h>
using namespace std;

int N;
char c[200009];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> c[i];
    }

    int l = 1, r = N;
    int ans = 0;
    while(l<=r){
        if(c[l]=='W' && c[r]=='R'){
            ans++;
            l++;
            r--;
        }else if(c[l]=='W'){
            r--;
        }else if(c[r]=='R'){
            l++;
        }else{
            l++;
            r--;
        }
    }
    std::cout << ans << endl;
    return 0;
}