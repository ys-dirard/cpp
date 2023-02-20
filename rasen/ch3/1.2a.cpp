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

int BubbleSort(int* A, int N){
    int cnt = 0;
    bool flg = true;
    while(flg){
        flg = false;
        for(int i=N-1;i>0;i--){
            if(A[i] < A[i-1]){
                int v = A[i];
                A[i] = A[i-1];
                A[i-1] = v;
                flg = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    int ans = BubbleSort(A, N);
    print_arr(A, N);
    cout << ans << endl;
    return 0;
}