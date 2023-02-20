#include <bits/stdc++.h>
#include <stack>
using namespace std;

int ans = 0;
stack<int> s;
char S[100];

int main(){
    
    while(scanf("%s", S) != EOF){
        if(S[0]=='+'){
            int tmp1 = s.top();
            s.pop();
            int tmp2 = s.top();
            s.pop();
            ans = tmp2 + tmp1;
            s.push(ans);
        }else if(S[0]=='-'){
            int tmp1 = s.top();
            s.pop();
            int tmp2 = s.top();
            s.pop();
            ans = tmp2 - tmp1;
            s.push(ans);
        }else if(S[0]=='*'){
            int tmp1 = s.top();
            s.pop();
            int tmp2 = s.top();
            s.pop();
            ans = tmp2 * tmp1;
            s.push(ans);
        }else{
            s.push(atoi(S));
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}