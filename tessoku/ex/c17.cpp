#include <bits/stdc++.h>

#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>

using namespace std;

int Q;
char qt;
string name;
deque<string> q1, q2;

int main(){
    cin >> Q;
    rep(i, 1, Q+1){
        cin >> qt;
        if(qt == 'A'){
            cin >> name;
            q2.push_back(name);
        }else if(qt == 'B'){
            cin >> name;
            q1.push_back(name);
        }else if(qt == 'C'){
            q1.pop_front();
        }else if(qt == 'D'){
            cout << q1.front() << endl;
        }

        while((int)q1.size() - (int)q2.size() >= 2){
            string r = q1.back();
            q1.pop_back();
            q2.push_front(r);
        }
        while((int)q1.size() - (int)q2.size() <= -1){
            string r = q2.front();
            q2.pop_front();
            q1.push_back(r);
        }
    }
    return 0;
}