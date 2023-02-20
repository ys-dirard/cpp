#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int &i: a) {
        cin >> i;
    }
    
    // k = 1,2,...,M について操作を行った場合に、1,2,...,N がそれぞれどこに行くかを求める
    vector<int> b(n + 1);
    iota(b.begin(), b.end(), 0); // 0から始まるn+1個の整数列を生成(0~n)
    for (int i: a) {
        swap(b[i], b[i + 1]);
    }
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        pos[b[i]] = i;
    }
    
    // 答えを求める
    iota(b.begin(), b.end(), 0);
    for (int i: a) {
        if (b[i] == 1) {
            cout << pos[b[i + 1]] << '\n';
        } else if (b[i + 1] == 1) {
            cout << pos[b[i]] << '\n';
        } else {
            cout << pos[1] << '\n';
        }
        swap(b[i], b[i + 1]);
    }
}
