#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    cin >> s;
    int ans = 0;

    for(int i=0;i<3;i++){
        if(s[i]=='1') ans++;
    }
    cout << ans << endl;
    return 0;
}