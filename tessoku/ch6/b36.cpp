#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;
    
    int n_on = 0;
    for (int i=0; i<S.size(); i++){
        if (S[i] == '1') n_on++;
    }
    if (abs(K - n_on) % 2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}