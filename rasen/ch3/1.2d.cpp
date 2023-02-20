#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,A[1000009];
int m = 0;
vector<int> G;
int cnt = 0;

void insersionSort(int* A, int n, int g){
    for(int i=g;i<n;i++){
        int v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v){
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(int* A, int n){
    int tmp = 1;
    while(tmp <= n){
        G.push_back(tmp);
        tmp = tmp * 3 + 1;
    }
    reverse(G.begin(), G.end());
    m = G.size();

    for(int i=0;i<m;i++){
        insersionSort(A, n, G[i]);
    }
}

void print_vec(vector<int> A, int N){
    for(int i=0;i<N;i++){
        cout << A[i];
        if(i != N-1) cout << " ";
    }
    cout << endl;
}

void print_arr(int* A, int N){
    for(int i=0;i<N;i++){
        cout << A[i];
        if(i != N-1) cout << endl;
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    shellSort(A, n);

    cout << m << endl;
    print_vec(G, m);
    cout << cnt << endl;
    print_arr(A, n);
    return 0;
}