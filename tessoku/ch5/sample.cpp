#include <bits/stdc++.h>
using namespace std;

int N;

void print_S(int n){
    if (n==0) return;
    print_S(n-1);
    cout << n << " ";
    print_S(n-1);
}

int main(){
    cin >> N;
    print_S(N);
    return 0;
}