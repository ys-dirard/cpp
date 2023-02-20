#include <bits/stdc++.h>
using namespace std;

long long N;
priority_queue<long long, vector<long long>, greater<long long>> q;

int main(){
    cin >> N;
    double rn = sqrt(N);
    for(long long i=1;i<=rn;i++){
        if(N % i == 0){
            q.push(i);
            if(i != rn){
                q.push(N / i);
            }
        }
    }
    while(!q.empty()){
        cout << q.top() << endl;
        q.pop();
    }
    return 0;
}