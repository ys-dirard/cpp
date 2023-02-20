#include <iostream>
using namespace std;

// ����
long long mod = 1000000007;
long long N, K, B;
long long C[11];

// ���̑��̕ϐ�
long long dp[10009][33];

int main() {
	// Step #1. ����
	cin >> N >> B >> K;
	for (int i = 1; i <= K; i++) cin >> C[i];

	// Step #2. ���I�v��@
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < B; j++) {
			for (int k = 1; k <= K; k++) {
				int nex = (10 * j + C[k]) % B;
				dp[i + 1][nex] += dp[i][j];
				dp[i + 1][nex] %= mod;
			}
		}
	}

	// Step #3. �o��
	cout << dp[N][0] << endl;
	return 0;
}