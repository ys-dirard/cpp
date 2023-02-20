#include <bits/stdc++.h>
using namespace std;

int N;
char C;
string A;
int score = 0; // W:0, R:1, B:2

int main(){
    cin >> N >> C >> A;
    for(int i=0;i<A.size();i++){
        if(A[i] == 'R'){
            score += 1;
        } else if (A[i] == 'B'){
            score += 2;
        }
    }

    if(score % 3 == 0 && C == 'W'){
        cout << "Yes" << endl;
    }else if(score % 3 == 1 && C == 'R'){
        cout << "Yes" << endl;
    }else if(score % 3 == 2 && C == 'B'){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}