#include <iostream>
#include <algorithm>
using namespace std;

int n;
int m, M;
int R[200009];

int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> R[i];
    m = 2000000000;
    M = -2000000000;

    for(int i=1;i<=n;i++){
        M = max(M, R[i] - m);
        m = min(m, R[i]);
    }

    cout << M << endl;
    return 0;
}