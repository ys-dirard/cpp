#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100009], B[100009];
vector<int> v[100009];

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> A[i] >> B[i];
        v[A[i]].push_back(B[i]);
        v[B[i]].push_back(A[i]);
    }

    for(int i=1;i<=N;i++){
        cout << i << ": {";
        for(int j: v[i]){
            cout << j;
            if(j!=v[i][v[i].size()-1]) cout << ", ";
        }
        cout << "}" << endl;
    }
    return 0;
}