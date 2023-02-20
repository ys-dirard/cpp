#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

// ����
long long N, M;
long long A[100009], B[100009], C[100009];

// �O���t�E�ŒZ����
long long dist[100009];
long long dist1[100009];
long long distN[100009];
vector<pair<int, long long>> G[100009];

void dijkstra(int stt) {
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
	for (int i = 1; i <= N; i++) dist[i] = (1LL << 60);
	dist[stt] = 0;
	Q.push(make_pair(0, stt));

	while (!Q.empty()) {
		int pos = Q.top().second; Q.pop();
		for (int i = 0; i < G[pos].size(); i++) {
			int to = G[pos][i].first;
			long long cost = G[pos][i].second;
			if (dist[to] > dist[pos] + cost) {
				dist[to] = dist[pos] + cost;
				Q.push(make_pair(dist[to], to));
			}
		}
	}
}

int main() {
	// Step #1. ����
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i] >> C[i];
		G[A[i]].push_back(make_pair(B[i], C[i]));
		G[B[i]].push_back(make_pair(A[i], C[i]));
	}

	// Step #2. ���_ 1 ����̍ŒZ���������߂�
	dijkstra(1);
	for (int i = 1; i <= N; i++) dist1[i] = dist[i];

	// Step #3. ���_ N ����̍ŒZ���������߂�
	dijkstra(N);
	for (int i = 1; i <= N; i++) distN[i] = dist[i];

	// Step #4. �o��
	for (int i = 1; i <= N; i++) {
		long long Answer = dist1[i] + distN[i];
		cout << Answer << endl;
	}
	return 0;
}