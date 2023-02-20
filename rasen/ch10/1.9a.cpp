#include <bits/stdc++.h>
using namespace std;

int n, x;
int T[300];

int get_parent(int x){
    return x / 2;
}

int get_left(int x){
    return 2 * x;
}
int get_right(int x){
    return 2 * x + 1;
}

void print(int x){
    cout << "node " << x;
    cout << ": key = " << T[x] << ", ";
    if(get_parent(x) > 0) cout << "parent key = " << T[get_parent(x)] << ", ";
    if(get_left(x) <= n) cout << "left key = " << T[get_left(x)] << ", ";
    if(get_right(x) <= n) cout << "right key = " << T[get_right(x)] << ", ";
    cout << endl;
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> T[i];
    }

    for(int i=1;i<=n;i++) print(i);
    return 0;
}