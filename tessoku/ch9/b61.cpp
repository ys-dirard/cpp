#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100009], B[100009];
vector<int> v[100009];

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> A[i] >> B[i];
        v[A[i]].push_back(B[i]);
        v[B[i]].push_back(A[i]);
    }

    int val = 0;
    int ans = -1;
    for(int i=1;i<=N;i++){
        if((int)v[i].size() > val){
            val = (int)v[i].size();
            ans = i;
        }
    }
    std::cout << ans << endl;
    return 0;
}