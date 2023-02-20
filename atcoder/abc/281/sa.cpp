#include <iostream>
#include <vector>
using namespace std;

// N: 頂点数, M: 辺の数, A[i]↔B[i]: 無向辺
int N, M, A[100009], B[100009];
// 隣接リスト用vectorの配列
vector<int> graph[100009];

int main(){
    // input
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> A[i] >> B[i];
        // 頂点A[i]が頂点B[i]と隣接していることを記録
        graph[A[i]].push_back(B[i]);
        // 頂点B[i]が頂点A[i]と隣接していることを記録
        graph[B[i]].push_back(A[i]);
    }
    return 0;
}