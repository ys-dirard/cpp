#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
    public:
    int dat[600000], siz=1;

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
            dat[pos] = dat[pos * 2] + dat[pos * 2 + 1];
        }
    }

    // return answer
    int query(int l, int r, int a, int b, int u){
        if(r <= a || b <= l) return 0;
        if(l <= a && b <= r) return dat[u];
        int m = (a+b)/2;
        int answerL = query(l, r, a, m, u*2);
        int answerR = query(l, r, m, b, u*2+1);
        return answerL + answerR;
    }
};


int N;
int A[150009];
SegmentTree tree;

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> A[i];
    }

    tree.init(N);
    
    long long answer = 0;
    for(int i=1;i<=N;i++){
        answer += tree.query(A[i] + 1, N + 1, 1, tree.siz + 1, 1);
        tree.update(A[i], 1);
    }

    cout << answer << endl;
    return 0;
}
