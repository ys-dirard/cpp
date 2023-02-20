#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
    public:
    int dat[300000], siz=1;

    // initialize dat
    void init(int N){
        siz = 1;
        while(siz < N) siz *= 2;
        for(int i=1;i<siz*2;i++) dat[i] = 0;
    }

    // update tree
    void update(int pos, int x){
        pos = pos + siz - 1;
        dat[pos] = x;
        while(pos > 1){
            pos /= 2;
            dat[pos] = min(dat[pos * 2], dat[pos * 2 + 1]);
        }
    }

    // return answer
    int query(int l, int r, int a, int b, int u){
        if(r <= a || b <= l) return 1000000000;
        if(l <= a && b <= r) return dat[u];
        int m = (a+b)/2;
        int answerL = query(l, r, a, m, u*2);
        int answerR = query(l, r, m, b, u*2+1);
        return min(answerL, answerR);
    }
};


int N, L, R;
int X[100009];
int dp[100009];
SegmentTree tree;

int main(){
    cin >> N >> L >> R;
    for(int i=1;i<=N;i++){
        cin >> X[i];
    }

    tree.init(N);
    dp[1] = 0;
    tree.update(1, 0);

    for(int i=2;i<=N;i++){
        int posL = lower_bound(X+1, X+N+1, X[i]-R) - X;
        int posR = lower_bound(X+1, X+N+1, X[i]-L+1) - X - 1;
        dp[i] = tree.query(posL, posR+1, 1, tree.siz+1, 1) + 1;
        tree.update(i, dp[i]);
    }

    cout << dp[N] << endl;
    return 0;
}
