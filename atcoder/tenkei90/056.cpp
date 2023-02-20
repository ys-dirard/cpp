#include <bits/stdc++.h>
using namespace std;

int N, S;
int A[109], B[109];
bool buy[109][100009];

int main(){
    cin >> N >> S;
    for(int i=1;i<=N;i++){
        cin >> A[i] >> B[i];
    }

    for(int i=0;i<=N;i++){
        for(int j=0;j<=S;j++){
            buy[i][j] = false;
        }
    }

    buy[0][0] = true;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=S;j++){
            if(j-A[i]>=0 && buy[i-1][j-A[i]]) buy[i][j] = true;
            if(j-B[i]>=0 && buy[i-1][j-B[i]]) buy[i][j] = true;
        }
    }

    if(buy[N][S]){
        string ans = "";
        int pos = S;
        int i = N;
        while(pos > 0){
            if(pos - A[i] >= 0 && buy[i-1][pos-A[i]]){
                pos = pos - A[i];
                i--;
                ans = "A" + ans;
            }else{
                pos = pos - B[i];
                i--;
                ans = "B" + ans;
            }
        }
        cout << ans << endl;
    }else{
        cout << "Impossible" << endl;
    }
    return 0;
}