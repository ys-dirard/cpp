#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long a, b, c;
    cin >> a >> b >> c;
    unsigned long long t = 1ULL;

    for(int i=0;i<b;i++){
        t *= c;
    }
    
    // cout << a << endl;
    // cout << t << endl;
    // cout << (a<t) << endl;
    if(a < t) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}