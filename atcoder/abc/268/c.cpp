#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int N, p[400000], ans = 0, count = 0;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> p[i];
        p[i + N] = p[i];
    }
    for (int i=0; i<N; i++){
        count = 0;
        for (int j = 0; j < N; j++){
            if (p[j - 1 + i] == j || p[j + i] == j || p[j + 1 + i] == j) count++;
            if (count + N - j < ans) break;
        }
        if (count > ans) ans = count;
    }
    cout << ans;
    return 0;
}