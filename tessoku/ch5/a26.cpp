#include <bits/stdc++.h>
using namespace std;

int Q, X[10009];

int main(){
    cin >> Q;
    for (int i=1; i<=Q; i++) cin >> X[i];

    for (int i=1; i<=Q; i++){
        double sqrt_xi = sqrt(X[i]);
        bool is_prime = true;
        for (int j=2; j<=sqrt_xi; j++){
            if (X[i] % j == 0) is_prime = false;
        }
        if (is_prime) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}