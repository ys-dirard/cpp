#include <bits/stdc++.h>
using namespace std;

int n;
list<int> L;

int main(){
    cin >> n;
    int x;
    for(int i=0;i<n;i++){
        string command;
        cin >> command;
        if(command=="insert"){
            cin >> x;
            L.push_front(x);
        }else if(command=="delete"){
            cin >> x;
            for(auto itr=L.begin();itr!=L.end();itr++){
                if(*itr==x){
                    L.erase(itr);
                    break;
                }
            }
        }else if(command=="deleteFirst"){
            L.pop_front();
        }else{
            L.pop_back();
        }
    }
    for(auto itr=L.begin();itr!=L.end();itr++){
        if(itr!=L.begin()) cout << " ";
        cout << *itr;
    }
    cout << endl;
    return 0;
}