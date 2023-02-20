#include <bits/stdc++.h>
using namespace std;

int N, a[109];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> a[i];

    sort(a+1, a+1+N);
    int ap=0, bp=0;
    for(int i=1;i<=N;i++){
        if(i%2==1) ap += a[N-i+1];
        else bp += a[N-i+1];
    }
    cout << ap - bp << endl;
    return 0;
}