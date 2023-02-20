#include <bits/stdc++.h>
using namespace std;

// Jessica's Reading Problem (POJ No.3320)

// Jessicaは分厚い本を読む
// 試験に合格するためには書かれている事項を全てマスターする必要がある
// 本はPページからなり、iページ目にはaiについて書かれている
// 本には何度も同じ内容が書かれている
// 連続するページで全てカバーしようとすると
// 最小何ページで済むか求める

// input
// P=5
// a={1, 8, 8, 8, 1}
// output
// 2 (1,2ページ目を読めばよい)

int P, a[1000009];

int solve(){
    set<int> all;
    for(int i=0;i<P;i++){
        all.insert(a[i]);
    }
    int n = all.size();

    // syakutori
    int s = 0, t = 0;
    int num = 0;
    map<int, int> cnt;
    int res = P;
    while(1){
        while(t<P && num < n){
            if(cnt[a[t++]]++ == 0){
                num++;
            }
        }
        if(num < n) break;

        res = min(res, t-s);
        if(--cnt[a[s++]] == 0){
            num--;
        }
    }

    return res;
}

int main(){
    cin >> P;
    for(int i=0;i<P;i++){
        cin >> a[i];
    }

    int ans = solve();
    cout << ans << endl;
    return 0;
}