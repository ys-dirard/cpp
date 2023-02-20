#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int A[5], count = 0;
    for (int i=0; i<5; i++){
        cin >> A[i];
        bool flg = true;
        for (int j=0; j<i;j++){
            if (A[i] == A[j]){
                flg = false;
            }
        }
        if (flg) count++;
    }
    cout << count;
    return 0;
}