#include <bits/stdc++.h>
using namespace std;

long long N;

int main(){
    cin >> N;
    long long R[20][10];
    long long Power10[20];

    Power10[0] = 1;
	for (int i = 1; i <= 16; i++) Power10[i] = 10LL * Power10[i - 1];
    long long ans = 0;
    for (int i=15; i>=0; i--){
        int u = (N / (long long)pow(10, i)) % 10LL;

		// R[i][j] の値を求める
		for (int j = 0; j < 10; j++) {
			if (j < u) {
				R[i][j] = (N / Power10[i + 1] + 1LL) * Power10[i];
			}
			if (j == u) {
				R[i][j] = (N / Power10[i + 1]) * Power10[i] + (N % Power10[i]) + 1LL;
			}
			if (j > u) {
				R[i][j] = (N / Power10[i + 1]) * Power10[i];
			}
        }
    }

	for (int i = 0; i <= 15; i++) {
		for (int j = 0; j < 10; j++) ans += 1LL * j * R[i][j];
	}
    cout << ans << endl;
    return 0;
}