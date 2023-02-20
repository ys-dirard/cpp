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

int SelectionSort(int* A, int N){
    int cnt = 0;

    for(int i=0;i<N;i++){
        int minj = i;
        for(int j=i;j<N;j++){
            if(A[minj] > A[j]){
                minj = j;
            }
        }
        int tmp = A[i];
        A[i] =  A[minj];
        A[minj] = tmp;
        if(minj != i) cnt++;
    }
    return cnt;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];

    int ans = SelectionSort(A, N);
    print_arr(A, N);
    cout << ans << endl;
    return 0;
}