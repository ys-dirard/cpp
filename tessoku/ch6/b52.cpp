#include <bits/stdc++.h>
using namespace std;

int N, X;
string A;
queue<int> positions;

int main(){
    cin >> N >> X;
    cin >> A;

    positions.push(X);
    A[X-1] = '@';

    while(!positions.empty()){
        int pos = positions.front();
        positions.pop();
        if(pos-2 >=0 && A[pos-2]=='.'){
            positions.push(pos-1);
            A[pos-2] = '@';
        }
        if(pos<A.size() && A[pos]=='.'){
            positions.push(pos+1);
            A[pos] = '@';
        }
    }
    cout << A << endl;
    return 0;
}