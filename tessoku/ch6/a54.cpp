#include <bits/stdc++.h>
using namespace std;

int Q, q, y;
string x;
map<string, int> grade;

int main(){
    cin >> Q;
    for(int i=1;i<=Q;i++){
        cin >> q;
        if(q==1){
            cin >> x >> y;
            grade[x] = y;
        }else if(q==2){
            cin >> x;
            cout << grade[x] << endl;
        }
    }
    return 0;
}