#include <bits/stdc++.h>
using namespace std;

int N;
string S, T;

int get_hamming_distance(string S, string T){
    int ans = 0;
    for(int i=0;i<S.size();i++){
        if(S[i] != T[i]) ans++;
    }
    return ans;
}

int main(){
    cin >> N >> S >> T;
    
    int dist = get_hamming_distance(S, T);
    int ns = 0, nt = 0;
    // cout << dist << endl;
    if(dist % 2 == 1){
        cout << -1 << endl;
        return 0;
    }

    string ans = "";
    for(int i=0;i<S.size();i++){
        if(S[i] == T[i]){
            ans += '0';
        }else if(ns<dist/2 && nt<dist/2){
            if(S[i] < T[i]){
                ans += S[i];
                ns++;
            }else{
                ans += T[i];
                nt++;
            }
        }else{
            if(nt<dist/2){
                ans += T[i];
                nt++;
            }else{
                ans += S[i];
                ns++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}