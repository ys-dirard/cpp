#include <bits/stdc++.h>
using namespace std;

const int NIL = -1;

int n, pos;
vector<int> pre(40, -1), in(40, -1), post;

// [l, r)
void reconstruction(int l, int r){
    if(l>=r) return;
    int root = pre[pos++];
    int m = distance(in.begin(), find(in.begin(), in.end(), root));
    reconstruction(l, m);
    reconstruction(m+1, r);
    post.push_back(root);
}

void solve(){
    pos = 0;
    reconstruction(0, n);
    for(int i=0;i<n;i++){
        if(i) cout << " ";
        cout << post[i];
    }
    cout << endl;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> pre[i];
    for(int i=0;i<n;i++) cin >> in[i];

    solve();
    return 0;
}