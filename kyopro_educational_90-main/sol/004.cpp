#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int H, W;
int A[2009][2009];
int Row[2009], Column[2009];
int Answer[2009][2009];

int main() {
	// Step #1. ����
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	
	// Step #2. �O�v�Z
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			Row[i] += A[i][j];
			Column[j] += A[i][j];
		}
	}

	// Step #3. �����̌v�Z
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			Answer[i][j] = Row[i] + Column[j] - A[i][j];
		}
	}

	// Step #4. �o��
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (j >= 2) printf(" ");
			printf("%d", Answer[i][j]);
		}
		printf("\n");
	}
	return 0;
}