#include <bits/stdc++.h>
using namespace std;

// Layout (POJ No.3169)

/*
N頭の牛を飼っており各牛には1~Nの番号がついている。
牛たちは食事をもらうために番号順に一列に並んでいる。
いくつかの牛は互いに仲が良くある距離以内に並びたいと考えており、
またいくつかの牛は互いに仲が悪く、ある距離以上離れて並びたいと
考えている。牛は同じ場所に複数並ぶことも可能。
ML個の仲の良い牛の情報(AL, BL, DL)と、MD個の仲の悪い牛の情報(AD, BD, DD)
が与えられる。それぞれ、牛ALと牛BLの最大距離DLならびに牛ADと牛BDの最小距離DDを表す。
この制約を全て満たすような並び方のうち、1番の牛とN番の牛の間の最大距離を求める。
そのような並び方が存在しない場合は-1、いくらでも離れられる場合は-2を出力する。

制約：
2<=N<=1000
1<=ML, MD<=10000
1<=AL<BL<=N
1<=AD<BD<=N
1<=CL, DD<=1000000

input:
[N ML MD]
[AL BL DL] x ML
[AD BD DD] x MD
4 2 1
1 3 10
2 4 20
2 3 3

output:
27 (0, 7, 10, 27)

ベルマンフォード法！！
s->tへの最短距離をd(t)とすると
コストwの辺e=(u, v)にたいして
d(u) + w >= d(v)
となる
-> d(v) - d(u) <= w
これより
d(t) - d(u') <= w'
d(v') - d(s) <= w''
-> d(t) - d(s) <= w```
よって答えはd(t) - d(s)の最大値となる

今回の問題では、
d[AL] + DL >= d[BL]
d[AD] + DD <= d[BD]
-> d[BL] - d[AL] <= DL
   d[AD] - d[BD] <= -DD
となるため、ALからBLへDLの辺を
BDからADへDDの辺を張ればよい
-> d[N] - d[1]（の最大値）が答えになる(=これが最短距離になる)
d[i]<=d[i+1] -> d[i] - d[i+1] <= 0も忘れない！
*/

const long long INF = 1e17;
// 辺
struct edge
{
	int from;
	int to;
	int cost;
};

// ベルマンフォード法 (1.2 負閉路の影響を受ける頂点を調べる)
// 負の閉路が存在する場合 true を返し, 負閉路の影響を受ける頂点は -INF にセットされる
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
bool bellman_ford(const std::vector<edge>& edges, std::vector<long long>& distances, int startIndex)
{
	distances[startIndex] = 0;

	for (size_t i = 0; i < distances.size(); ++i)
	{
		bool changed = false;

		// 各辺について
		for (const auto& edge : edges)
		{
			// (INF + cost) は INF なので処理しない
			if (distances[edge.from] == INF)
			{
				continue;
			}

			// to までの新しい距離
			const long long d = (distances[edge.from] + edge.cost);

			// d が現在の記録より小さければ更新
			if (d < distances[edge.to])
			{
				distances[edge.to] = d;

				changed = true;
			}
		}

		// どの頂点も更新されなかったら終了
		if (!changed)
		{
			return false;
		}
	}

	// 頂点数分だけさらに繰り返し, 負閉路の影響を受ける頂点に -INF を伝播
	for (size_t i = 0; i < distances.size(); ++i)
	{
		for (const auto& edge : edges)
		{
			if (distances[edge.from] == INF)
			{
				continue;
			}

			const long long d = (distances[edge.from] + edge.cost);

			if (d < distances[edge.to])
			{
				// 負閉路の影響を受ける頂点を -INF に
				distances[edge.to] = -INF;
			}
		}
	}

	return true;
}


int N, ML, MD;
int AL[10009], BL[10009], AD[10009], BD[10009], DL[10009], DD[10009];
vector<edge> edges;
vector<long long> dist;


int main(){
    cin >> N >> ML >> MD;
    for(int i=0;i<ML;i++){
        cin >> AL[i] >> BL[i] >> DL[i];
        edges.push_back({--AL[i], --BL[i], DL[i]});
    }
    for(int i=0;i<MD;i++){
        cin >> AD[i] >> BD[i] >> DD[i];
        edges.push_back({--BD[i], --AD[i], -DD[i]});
    }
    for(int i=0;i<N-1;i++){
        edges.push_back({i+1, i, 0});
    }
    dist.resize(N, INF);

    bool neg_loop = bellman_ford(edges, dist, 0);
    if(dist[N-1]==INF) cout << -1 << endl;
    else if(neg_loop) cout << -2 << endl;
    else cout << dist[N-1] << endl;
    return 0;
}