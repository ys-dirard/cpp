#include <bits/stdc++.h>
using namespace std;
#define ll long long

class state{
public:
    ll d, c, s;
    state(ll d=0, ll c=0, ll s=0): d(d), c(c), s(s) {}

    bool operator<(state s){
        return this->d < s.d;
    }
};

const ll INF = (1LL<<60);

ll N;
ll D[5009], C[5009], S[5009];
state states[5009];
ll dp[5009][5009]; // dp[i][j]: i個目までの仕事でj日目に得られている最大報酬

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> D[i] >> C[i] >> S[i];
        states[i] = state(D[i], C[i], S[i]);
    }

    sort(states+1, states+N+1);

    // for(int i=1;i<=N;i++){
    //     cout << states[i].d << " " << states[i].c << " " << states[i].s << endl;
    // }

    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            dp[i][j] = 0;
        }
    }

    for(int i=1;i<=N;i++){
        int limit = states[i].d;
        for(int j=0;j<=5000;j++){
            if(j<=limit && j-states[i].c>=0){
                dp[i][j] = max({dp[i][j-1], dp[i-1][j], dp[i-1][j-states[i].c]+states[i].s});
            }else if(j > limit){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=0;j<=10;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[N][5000] << endl;
    return 0;
}