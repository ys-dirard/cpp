#include <bits/stdc++.h>
using namespace std;

int N, A[109];

void print_arr(int* A, int N){
    for(int i=0;i<N;i++){
        cout << A[i];
        if(i != N-1) cout << " ";
    }
    cout << endl;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];

    // 選択ソート
    for(int i=1;i<N;i++){
        print_arr(A, N);
        int v = A[i];
        int j = i - 1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
    print_arr(A, N);
    return 0;
}