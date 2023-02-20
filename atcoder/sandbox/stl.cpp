#include <bits/stdc++.h>
using namespace std;

int main(){
    // abs ///////////////////////////////////////////////////////////////////
    cout << "abs" << endl;
    printf("%.12lf\n", abs(100 - 182.44));

    // sin/cos/tan ///////////////////////////////////////////////////////////////////
    double pi = 3.141592653589793238;
    double x = 30;
    cout << "sin / cos / tan" << endl;
    printf("%.12lf\n", sin(x / 180.0 * pi));
    printf("%.12lf\n", cos(x / 180.0 * pi));
    printf("%.12lf\n", tan(x / 180.0 * pi));

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

    // min / max ///////////////////////////////////////////////////////////////////
    cout << max({103, 168, 103}) << endl;

    // 例 2: {c[1], c[2], ..., c[N]} の最小値を出力する方法 1 つ目
    int N=5, c[100009]={19, 33, 11, 452, 2, 111}, minx = 2147483647;
    // cin >> N;

    // for (int i = 1; i <= N; i++) cin >> c[i];
    for (int i = 1; i <= N; i++) minx = min(minx, c[i]);
    cout << minx << endl;

    // 例 3: {c[1], c[2], ..., c[N]} の最小値を出力する方法 2 つ目 min_element(l, r)->[l, r)
    cout << *min_element(c + 1, c + N + 1) << endl;
    return 0;
}