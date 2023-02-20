#include <bits/stdc++.h>
using namespace std;

int H, W;
int c[1409][1409];
int hist[1409][1409];
stack<pair<int, int>> st;
int ans = 0;

int main(){
    cin >> H >> W;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> c[i][j];
        }
    }
    for(int i=0;i<=H;i++){
        for(int j=0;j<=W;j++){
            hist[i][j] = 0;
        }
    }

    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(c[i][j] == 0){
                hist[i][j] = hist[i-1][j] + 1;
            }
        }
    }

    for(int i=1;i<=H;i++){
        stack<pair<int, int>> st;
        for(int j=1;j<=W+1;j++){
            int pre = j;
            if(st.empty()){
                st.push({j, hist[i][j]});
            }else{
                if(hist[i][j]>st.top().second){
                    st.push({j, hist[i][j]});
                }else if(hist[i][j]<st.top().second){
                    while(!st.empty() && st.top().second >= hist[i][j]){
                        ans = max(ans, (j-st.top().first)*st.top().second);
                        pre = st.top().first;
                        st.pop();
                    }
                    st.push({pre, hist[i][j]});
                }
            }
        }
        // if(!st.empty()){
        //     ans = max(ans, (W-st.top().first+1)*st.top().second);
        // }
    }

    cout << ans << endl;

    // for(int i=1;i<=H;i++){
    //     for(int j=1;j<=W;j++){
    //         cout << hist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}