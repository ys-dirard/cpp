#include <bits/stdc++.h>
using namespace std;

int N, Q, A[200009];
int sift = 0;

void print(){
    for(int i=1;i<=N;i++){
        cout << A[(i+sift-1)%N+1] << " ";
    }
    cout << endl;
}

int main(){
    cin >> N >> Q;
    for(int i=1;i<=N;i++) cin >> A[i];

    int t, x, y;
    for(int i=1;i<=Q;i++){
        cin >> t >> x >> y;
        if(t==1){
            // cout << A[(x+sift-1)%N+1] << " " << A[(y+sift-1)%N+1] << endl;
            // print();
            swap(A[(x+sift-1)%N+1], A[(y+sift-1)%N+1]);
        }else if(t==2){
            sift = (sift+N-1)%N;
            // cout << sift << endl;
        }else{
            cout << A[(x+sift-1)%N+1] << endl;
        }
    }
    return 0;
}