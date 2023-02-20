#include <bits/stdc++.h>

#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>

using namespace std;

string S[10];
int ans = 0;

int main(){
    rep(i, 0, 9) cin >> S[i];
    rep(r, 0, 9){
        rep(c, 0, 9){
            rep(i, 0, r){
                rep(j, c, 9){
                    if(!(i==r && j==c)){
                        int y = r - i;
                        int x = j - c;
                        bool check = ((r+x < 9) && (c+x+y < 9));
                        if(check){
                            bool sq = (S[r][c]=='#' && S[r+x][c+y]=='#' && S[r-y][c+x]=='#' && S[r+x-y][c+x+y]=='#');
                            if(sq){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}