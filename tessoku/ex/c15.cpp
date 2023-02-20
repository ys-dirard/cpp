#include <bits/stdc++.h>

#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>

using namespace std;

int N, K, L[100009], R[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ql;
priority_queue<pair<int, int>> qr;
int cntL[200009], cntR[200009];

int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> L[i] >> R[i];
        R[i] += K;
        ql.push(make_pair(R[i], L[i]));
        qr.push(make_pair(L[i], R[i]));
    }
    int tmp_endl = 0;
    int numl = 0;
    while(!ql.empty()){
        pair<int, int> tmpl = ql.top();
        ql.pop();
        if(tmpl.second >= tmp_endl){
            tmp_endl = tmpl.first;
            numl++;
            cntL[tmp_endl] = numl;
            
        }
    }

    int tmp_endr = 200000;
    int numr = 0;
    while(!qr.empty()){
        pair<int, int> tmpr = qr.top();
        qr.pop();
        if(tmpr.second <= tmp_endr){
            tmp_endr = tmpr.first;
            numr++;
            cntR[tmp_endr] = numr;
            
        }
    }

    for(int i=1;i<=200000;i++) cntL[i] = max(cntL[i], cntL[i-1]);
    for(int i=200000;i>=0;i--) cntR[i] = max(cntR[i], cntR[i+1]);

    for(int i=1;i<=N;i++){
        cout << cntL[L[i]] + 1 + cntR[R[i]] << endl;
    }
    return 0;
}