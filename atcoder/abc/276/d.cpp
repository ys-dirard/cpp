/* #region convenient */
#include <bits/stdc++.h>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>
using namespace std;
/* #endregion*/

ll N, a[1009];

ll gcd(ll a, ll b){
    while(a>0 && b>0){
        if(a>b){
            a = a % b;
        }else{
            b = b % a;
        }
    }
    if(a==0) return b;
    else return a;
}

int main(){
    cin >> N;
    rep(i, 1, N+1) cin >> a[i];

    ll gcd_ = gcd(a[1], a[2]);
    for(int i=3;i<=N;i++) gcd_ = gcd(gcd_, a[i]);
    ll gwari2 = 0, gwari3 = 0;
    ll tmp = gcd_;
    while(tmp % 2 == 0){
        tmp /= 2;
        gwari2++;
    }
    while(tmp % 3 == 0){
        tmp /= 3;
        gwari3++;
    }

    ll power2[39], power3[20]; // 2->30, 3->19
    power2[0] = 1;
    power3[0] = 1;
    for(int i=1;i<=30;i++) power2[i] = power2[i-1]*2;
    for(int i=1;i<=19;i++) power3[i] = power3[i-1]*3;
    // cout << gcd_ << endl;

    ll wari2=0, wari3=0;
    bool flg = true;
    rep(i, 1, N+1){
        int tmp_wari2 = 0, tmp_wari3 = 0;
        tmp = a[i];
        while(tmp % 2 == 0){
            tmp /= 2;
            tmp_wari2++;
        }
        while(tmp % 3 == 0){
            tmp /= 3;
            tmp_wari3++;
        }

        wari2 += tmp_wari2 - gwari2;
        wari3 += tmp_wari3 - gwari3;

        a[i] /= power2[tmp_wari2 - gwari2];
        a[i] /= power3[tmp_wari3 - gwari3];
        
        // cout << "a[" << i << "]: " << a[i] << endl;
        
        if(a[i] != gcd_){
            flg = false;
            break;
        }
    }

    if(flg) cout << wari2 + wari3 << endl;
    else cout << -1 << endl;
    return 0;
}