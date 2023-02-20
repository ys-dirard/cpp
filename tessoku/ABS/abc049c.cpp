#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    cin >> s;

    bool flg = false;
    int idx = 0;
    while(idx <= s.size()){
        if(s.size()-idx>=5 && s.substr(idx, 5)=="dream"){
            idx += 5;
            if(s.size()-idx>=2 && s.substr(idx, 2)=="er" && s.substr(idx+2, 1)!="a") idx += 2;
        }
        else if(s.size()-idx>=5 && s.substr(idx, 5)=="erase"){
            idx += 5;
            if(s.size()-idx>=1 && s.substr(idx, 1)=="r") idx += 1;
        }
        else break;
        if(idx==s.size()){
            flg = true;
        }
    }

    if(flg) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}