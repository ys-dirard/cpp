/* #region convenient */
#include <bits/stdc++.h>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>
using namespace std;
/* #endregion*/

int N, p[109];

int main(){
    cin >> N;
    rep(i, 1, N+1) cin >> p[i];

    int min_value = p[N];
    int min_pos = N;
    for(int i=N-1;i>0;i--){
        if(p[i] > min_value){
            // p[i]<->swap
            int pos_ = lower_bound(p+i, p+N+1, p[i]) - p - 1;
            int tmp = p[pos_];
            p[pos_] = p[i];
            p[i] = tmp;

            sort(p+i+1, p+N+1, greater<int>());
            break;
        }else{
            min_value = p[i];
        }
    }
    for(int i=1;i<=N;i++) cout << p[i] << " ";
    cout << endl;
    return 0;
}