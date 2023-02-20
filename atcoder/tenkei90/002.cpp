#include <bits/stdc++.h>
using namespace std;

bool check(string s, int N){
    stack<int> st;
    bool flg = true;
    for(int i=0;i<N;i++){
        if(s[i]=='('){
            st.push('(');
        }else{
            if(st.size()>0){
                st.pop();
            }else{
                flg = false;
            }
        }
    }
    if(st.size()!=0) flg = false;

    return flg;
}

string create(int n, int N){
    string res = "";
    for(int i=0;i<N;i++){
        if((n & (1<<i)) == 0) res += '(';
        else res += ')';
    }
    return res;
}

int N;
vector<string> vec;

int main(){
    cin >> N;
    
    for(int i=0;i<(1<<N);i++){
        string tmp = create(i, N);
        if(check(tmp, N)){
            vec.push_back(tmp);
            // cout << tmp << endl;
        }
    }

    sort(vec.begin(), vec.end());
    for(int i=0;i<vec.size(); i++){
        cout << vec[i] << '\n';
    }
    return 0;
}