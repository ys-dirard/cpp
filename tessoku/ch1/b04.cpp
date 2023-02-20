#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int N;
    cin >> N;
    int ans = 0;
    
    for (int i=0; i<8; i++) {
        ans += (1 << i) * ((N / (int)pow(10, i)) % 10);
    }
    cout << ans << endl;
    return 0;
}