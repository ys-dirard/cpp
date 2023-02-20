#include <bits/stdc++.h>
using namespace std;

int N;
int L[300009], R[300009];
vector<pair<int, int>> tmp;

int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> L[i] >> R[i];
        tmp.push_back(make_pair(R[i], L[i]));
    }
    sort(tmp.begin(), tmp.end());
    int ans = 0;
    int tmp_r = 0;
    for(int i=0; i<N; i++){
        if(tmp[i].second >= tmp_r){
            ans += 1;
            tmp_r = tmp[i].first;
        }
    }

    cout << ans << endl;
    return 0;
}