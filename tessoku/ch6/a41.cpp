#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int main(){
    cin >> N;
    cin >> S;
    for (int i=0;i<S.size()-2;i++){
        if (S[i] == 'B' && S[i+1] == 'B' && S[i+2] == 'B'){
            cout << "Yes" << endl;
            return 0;
        }
        if (S[i] == 'R' && S[i+1] == 'R' && S[i+2] == 'R'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}