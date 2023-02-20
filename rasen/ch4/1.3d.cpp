#include <bits/stdc++.h>
using namespace std;

string S;
stack<int> s1;
stack<pair<int, int>> s2;

int main(){
    cin >> S;
    int sum = 0;
    for(int i=0;i<S.size();i++){
        if(S[i]=='\\'){
            s1.push(i);
        }else if(S[i]=='/' && s1.size()>0){
            int j = s1.top();
            s1.pop();
            sum += i - j;
            int a = i - j;
            while(s2.size()>0 && s2.top().first > j){
                a += s2.top().second;
                s2.pop();
            }
            s2.push({j, a});
        }
    }

    vector<int> ans;
    while(s2.size()>0){
        ans.push_back(s2.top().second);
        s2.pop();
    }
    reverse(ans.begin(), ans.end());

    cout << sum << endl;
    cout << ans.size();
    for(int i=0;i<ans.size();i++){
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}