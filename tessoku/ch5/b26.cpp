#include <bits/stdc++.h>
using namespace std;

long long N;
bool Deleted[1000009];

int main(){
    cin >> N;
    for (int i=2; i<=N; i++){
        Deleted[i] = false;
    }

    double sqrt_n = sqrt(N);
    for (int i=2; i<=sqrt_n; i++){
        for (int j=2; i*j<=N; j++){
            Deleted[i*j] = true;
        }
    }

    for (int i=2; i<=N; i++){
        if (!Deleted[i]) cout << i << endl;
    }

    return 0;
}