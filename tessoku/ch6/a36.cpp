#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    if (K % 2 != 0 || K < 2*N-2){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}