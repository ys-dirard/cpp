#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

// ����
long long N;
long long D[5009], C[5009], S[5009];

long long hantei(int mask) {
	long long CurrentTime = 0;
	long long CurrentMoney = 0;
	for (int i = 1; i <= N; i++) {
		if ((mask & (1 << (i - 1))) == 0) continue;
		if (CurrentTime + C[i] > D[i]) {
			// ���؂ɊԂɍ���Ȃ�
			return -1LL;
		}
		else {
			CurrentTime += C[i];
			CurrentMoney += S[i];
		}
	}
	return CurrentMoney;
}

int main() {
	// Step #1. ����
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> D[i] >> C[i] >> S[i];
	}

	// Step #2. D[i] �̏����Ƀ\�[�g
	vector<tuple<long long, long long, long long>> tup;
	for (int i = 1; i <= N; i++) {
		tup.push_back(make_tuple(D[i], C[i], S[i]));
	}
	sort(tup.begin(), tup.end());
	for (int i = 1; i <= N; i++) {
		D[i] = get<0>(tup[i - 1]);
		C[i] = get<1>(tup[i - 1]);
		S[i] = get<2>(tup[i - 1]);
	}

	// Step #3. ���d���� bit �S�T��
	long long Answer = 0;
	for (int i = 0; i < (1 << N); i++) {
		long long Score = hantei(i);
		Answer = max(Answer, Score);
	}

	// Step #4. �o��
	cout << Answer << endl;
	return 0;
}