#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

string eight2nine(string x){
    const int siz = x.size();
    vector<int> ix(20, 0);
    ull eight = 0ULL;

    for(ull i=0;i<siz;i++){
        ull tmp = x[siz-i-1] - '0';
        eight += tmp * (1ULL<<(i*3ULL));
    }
    // cout << eight << endl;

    string ans = "";
    ull wari = 9LL;
    for(int i=0;i<min((ull)(siz), 20ULL);i++){
        ull tmp = eight % wari;
        ans = to_string(tmp) + ans;

        eight = eight / wari;
    }
    while(ans[0]=='0' && ans.size()>1){
        ans.erase(ans.begin());
    }
    // cout << ans << endl;
    return ans;
}

void change(string &x){
    for(int i=0;i<min((ull)(x.size()), 20ULL);i++){
        if(x[i]=='8') x[i] = '5';
    }
}

string N;
ull K;

int main(){
    cin >> N >> K;
    for(int i=0;i<K;i++){
        N = eight2nine(N);
        change(N);
    }
    cout << N << endl;
    return 0;
}