#include <iostream>
#include <deque>
using namespace std;

int Q, T[1 << 20], X[1 << 20];

int main() {
	// Step #1. ����
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> T[i] >> X[i];

	// Step #2. �V�~�����[�V����
	deque<int> deq;
	for (int i = 1; i <= Q; i++) {
		if (T[i] == 1) deq.push_front(X[i]);
		if (T[i] == 2) deq.push_back(X[i]);
		if (T[i] == 3) cout << deq[X[i] - 1] << endl;
	}
	return 0;
}