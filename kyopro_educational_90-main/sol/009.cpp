#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	double px, py;
};

Point operator-(const Point& a1, const Point& a2) {
	return Point{ a1.px - a2.px, a1.py - a2.py };
}

double getangle(Point G) {
	// �_ G �̕Ίp�����߂�
	if (G.py >= 0.0) {
		double I = G.px / sqrt(G.px * G.px + G.py * G.py);
		double kaku = acos(I) * 180.0 / 3.14159265358979;
		return kaku;
	}
	else {
		double I = G.px / sqrt(G.px * G.px + G.py * G.py);
		double kaku = acos(I) * 180.0 / 3.14159265358979;
		return 360.0 - kaku;
	}
}

double getangle2(double I1, double I2) {
	// [�Ίp I1] - [���_] - [�Ίp I2] �̂Ȃ��p�x�����߂�
	// �Ⴆ�� I1 = 240���AI2 = 30���̂Ƃ��A���߂�p�x�� 150��
	double res = abs(I1 - I2);
	if (res >= 180.0) return 360.0 - res;
	return res;
}

int N;
Point G[2009];

double solve(int pos) {
	// �ŏ��ɕΊp�̏����Ƀ\�[�g����
	vector<double> vec;
	for (int i = 1; i <= N; i++) {
		if (i == pos) continue;
		Point SA = G[i] - G[pos];
		double angle = getangle(SA);
		vec.push_back(angle);
	}
	sort(vec.begin(), vec.end());

	// �_ A ��S�T�����āA�ł��Ίp�̑傫���Ȃ�_ C ��񕪒T���istd::lower_bound�j�ŋ��߂�
	double ret = 0.0;
	for (int i = 0; i < vec.size(); i++) {
		double target = vec[i] + 180.0;
		if (target >= 360.0) target -= 360.0;
		int pos1 = lower_bound(vec.begin(), vec.end(), target) - vec.begin();

		// �_ C �̌��͍��X 2 �ɍi���
		int CandIdx1 = pos1 % vec.size();
		int CandIdx2 = (pos1 + vec.size() - 1) % vec.size();
		double Candidate1 = getangle2(vec[i], vec[CandIdx1]);
		double Candidate2 = getangle2(vec[i], vec[CandIdx2]);
		ret = max({ ret, Candidate1, Candidate2 });
	}
	return ret;
}

// O(N^3) �̃A���S���Y���i�_ A, B, C ��S�T���j
double solve_Slow() {
	double Answer = 0.0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (i == j || i == k || j == k) continue;
				double I1 = getangle(G[i] - G[j]);
				double I2 = getangle(G[k] - G[j]);
				Answer = max(Answer, getangle2(I1, I2));
			}
		}
	}
	return Answer;
}

// O(N^2 log N) �̃A���S���Y��
double solve_Fast() {
	// �_ B ��S�T��
	double Answer = 0.0;
	for (int i = 1; i <= N; i++) {
		double ret = solve(i);
		Answer = max(Answer, ret);
	}
	return Answer;
}

int main() {
	// Step #1. ����
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> G[i].px >> G[i].py;
	}

	// Step #2. �o��
	double FinalAns = solve_Fast();
	printf("%.12lf\n", FinalAns);
	return 0;
}