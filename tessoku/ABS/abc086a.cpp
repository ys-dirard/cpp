#include <bits/stdc++.h>
using namespace std;

int a, b;

int main(){
    cin >> a >> b;
    if((a&1) && (b&1)) cout << "Odd" << endl;
    else cout << "Even" << endl;
    return 0;
}