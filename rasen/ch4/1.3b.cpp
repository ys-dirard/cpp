#include <bits/stdc++.h>
using namespace std;

int n, q;
string names[100009];
int times[100009];
queue<pair<string, int>> qu;

int main(){
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> names[i] >> times[i];
        qu.push({names[i], times[i]});
    }
    int total = 0;
    while(!qu.empty()){
        pair<string, int> tmp = qu.front();
        qu.pop();
        if(tmp.second <= q){
            total += tmp.second;
            cout << tmp.first << " " << total << endl;
        }else{
            total += q;
            qu.push({tmp.first, tmp.second - q});
        }
    }
    return 0;
}