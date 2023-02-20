#include <bits/stdc++.h>
using namespace std;

int N, Q;
int A[200009];

int index(int x, bool rev){
    if (rev){
        x = N - x + 1;
    }
    return x;
}

int main(){
    cin >> N >> Q;
    for (int i=1;i<=N;i++){
        A[i] = i;
    }

    bool rev = false;
    int type;
    int x, y;
    for (int i=1;i<=Q;i++){
        cin >> type;
        if (type==1){
            cin >> x >> y;
            A[index(x, rev)] = y;
        }
        else if (type==2){
            rev = !rev;
        }else{
            cin >> x;
            cout << A[index(x, rev)] << endl;
        }
    }
    return 0;
}