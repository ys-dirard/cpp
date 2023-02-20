#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> dict;
string cmd, x;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> cmd >> x;
        if(cmd=="insert"){
            dict[x]++;
        }else if(cmd=="find"){
            if(dict[x]) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    return 0;
}