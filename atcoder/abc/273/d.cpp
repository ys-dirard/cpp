#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int h, w, n, r, c, Q;
map<int, vector<int>> amp, bmp;
int main(void)
{
  cin >> h >> w >> r >> c >> n;
  for(int i = 1; i <= n; i++){
    int rr, cc;
    cin >> rr >> cc;
    amp[rr].push_back(cc), bmp[cc].push_back(rr);
  }
  for(auto &p : amp) sort(p.second.begin(), p.second.end());
  for(auto &p : bmp) sort(p.second.begin(), p.second.end());
  
  cin >> Q;
  char d; int l;
  for(int i = 1; i <= Q; i++){
    cin >> d >> l;
    if(d == 'L'){
      auto it = amp.find(r); int lb = 0;
      if(it != amp.end()){
        vector<int> &vec = it->second;
        auto it2 = lower_bound(vec.begin(), vec.end(), c);
        if(it2 != vec.begin()) it2--, lb = *it2;
      }
      c = max(c-l, lb+1);
    }
    if(d == 'U'){
      auto it = bmp.find(c); int lb = 0;
      if(it != bmp.end()){
        vector<int> &vec = it->second;
        auto it2 = lower_bound(vec.begin(), vec.end(), r);
        if(it2 != vec.begin()) it2--, lb = *it2;
      }
      r = max(r-l, lb+1);
    }
    if(d == 'R'){
      auto it = amp.find(r); int ub = w+1;
      if(it != amp.end()){
        vector<int> &vec = it->second;
        auto it2 = upper_bound(vec.begin(), vec.end(), c);
        if(it2 != vec.end()) ub = *it2;
      }
      c = min(c+l, ub-1);
    }
    if(d == 'D'){
      auto it = bmp.find(c); int ub = h+1;
      if(it != bmp.end()){
        vector<int> &vec = it->second;
        auto it2 = upper_bound(vec.begin(), vec.end(), r);
        if(it2 != vec.end()) ub = *it2;
      }
      r = min(r+l, ub-1);
    }
    cout << r << " " << c << "\n";
  }
  
  return 0;
}