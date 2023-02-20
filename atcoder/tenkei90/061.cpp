#include <bits/stdc++.h>
using namespace std;

int Q, t, x;
deque<int> yama;

int main(){
    cin >> Q;
    for(int i=1;i<=Q;i++){
        cin >> t >> x;
        if(t==1){
            yama.push_front(x);
        }else if(t==2){
            yama.push_back(x);
        }else{
            cout << yama[x-1] << endl;
        }
    }
    return 0;
}