#include <iostream>
using namespace std;

// ����
int N;
int C[100009], P[100009];
int Q;
int L[100009], R[100009];

// �ݐϘa
int Sum1[100009];
int Sum2[100009];

int main() {
	// Step #1. ����
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> C[i] >> P[i];
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> L[i] >> R[i];

	// Step #2. 1 �g�E2 �g���ꂼ��̗ݐϘa�����
	for (int i = 1; i <= N; i++) {
		Sum1[i] = Sum1[i - 1];
		Sum2[i] = Sum2[i - 1];
		if (C[i] == 1) Sum1[i] += P[i];
		if (C[i] == 2) Sum2[i] += P[i];
	}

	// Step #3. �N�G���ɓ�����
	for (int i = 1; i <= Q; i++) {
		int Answer1 = Sum1[R[i]] - Sum1[L[i] - 1];
		int Answer2 = Sum2[R[i]] - Sum2[L[i] - 1];
		cout << Answer1 << " " << Answer2 << endl;
	}
	return 0;
}