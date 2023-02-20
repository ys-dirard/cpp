#include <bits/stdc++.h>
using namespace std;

int main(){
    // string ///////////////////////////////////////////////////////////////////
    cout << "string" << endl;
    string a, b;
    a = "aaaaaa";
    b = "bb";
    string cs = a + b;
    cout << cs.substr(0, 10) << endl; // 0から10文字(10文字に足りない場合はcs.size()文字！)
    // if (cs.size() <= 10) cout << cs << endl;
    // else cout << c.substr(0, 10) << endl;

    // 例 2: 入力した文字列 s の偶数文字目を 'z' に変えて出力します。
    string s;
    s = "ssssssssssss";
    for (int i = 0; i < s.size(); i += 2) s[i] = 'z';
    cout << s << endl;
    return 0;
}