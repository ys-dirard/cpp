#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string S, T;
    cin >> S >> T;
    int s_l = S.length(), t_l = T.length();

    string ans = "Yes";
    if (s_l > t_l) {
        ans = "No";
    } else {
        for (int i=0; i<s_l; i++){
            if (S[i] != T[i]) {
                ans = "No";
            }
        }
    }
    cout << ans;
    return 0;
}