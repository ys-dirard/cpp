#include <bits/stdc++.h>
using namespace std;

int N;
string s;
set<string> st;

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> s;
        if(st.find(s) == st.end()){
            st.insert(s);
            cout << i << endl;
        }
    }
    return 0;
}