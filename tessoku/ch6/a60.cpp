#include <bits/stdc++.h>
using namespace std;

int N;
int A[200009];
stack<pair<int, int>> S;

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];

    for(int i=1;i<=N;i++){

        while(!S.empty()){
            pair<int, int> p = S.top();
            if(p.first > A[i]){
                S.push(make_pair(A[i], i));
                cout << p.second << " ";
                break;
            }else{
                S.pop();
            }
        }
        if(S.empty()){
            cout << -1 << " ";
            S.push(make_pair(A[i], i));
        }
        
    }
    return 0;
}