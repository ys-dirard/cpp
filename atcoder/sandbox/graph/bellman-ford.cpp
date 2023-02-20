#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17;

// ※頂点番号は0-originになっている！！！

// 辺
struct edge
{
	int from;
	int to;
	int cost;
};
// SPFAは隣接リスト形式、
using Graph = std::vector<std::vector<edge>>;

// ベルマンフォード法 (1.1 基本実装)
// 負閉路が存在する場合 true を返す
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
// 計算量O(|V||E|)
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

	// 頂点回数分だけループしても更新が続くのは, 負閉路が存在するから
	return true;
}

// ベルマンフォード法 (1.2 負閉路の影響を受ける頂点を調べる)
// 負の閉路が存在する場合 true を返し, 負閉路の影響を受ける頂点は -INF にセットされる
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
bool bellman_ford2(const std::vector<edge>& edges, std::vector<long long>& distances, int startIndex)
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

// ベルマンフォード法 (1.3 最短経路を再構築する)
// 負の閉路が存在する場合 true を返し, 負閉路の影響を受ける頂点は -INF にセットされる
// 頂点 targetIndex が負閉路の影響を受けない場合, 頂点 startIndex からの最短経路を path に格納する
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
bool BellmanFord(const std::vector<edge>& edges, std::vector<long long>& distances, int startIndex, int targetIndex, std::vector<int>& path)
{
	distances[startIndex] = 0;

	// 直前の頂点を記録する配列
	std::vector<int> p(distances.size(), -1);

	bool changed = false;

	for (size_t i = 0; i < distances.size(); ++i)
	{
		changed = false;

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

				// 直前の頂点を記録
				p[edge.to] = edge.from;

				changed = true;
			}
		}

		// どの頂点も更新されなかったら終了
		if (!changed)
		{
			break;
		}
	}

	if (changed) // 負閉路あり
	{
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
	}

	if ((distances[targetIndex] != INF)
		&& (distances[targetIndex] != -INF)) // 頂点 targetIndex に到達不可または負閉路が影響する場合は最短経路無し
	{
		// 経路を再構築
		for (int i = targetIndex; i != -1; i = p[i])
		{
			path.push_back(i);
		}

		std::reverse(path.begin(), path.end());
	}

	return changed;
}

// ベルマンフォード法 (1.4 SPFA 基本実装)
// 負閉路が存在する場合 true を返す
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
bool SPFA(const Graph& graph, std::vector<long long>& distances, int startIndex)
{
	const size_t N = distances.size();
	std::vector<int> counts(N);
	std::vector<bool> inqueue(N);
	std::queue<int> q;

	distances[startIndex] = 0;
	q.push(startIndex);
	inqueue[startIndex] = true;

	while (!q.empty())
	{
		const int from = q.front(); q.pop();
		inqueue[from] = false;

		for (const auto& edge : graph[from])
		{
			// to までの新しい距離
			const long long d = (distances[from] + edge.cost);

			// d が現在の記録より小さければ更新
			if (d < distances[edge.to])
			{
				distances[edge.to] = d;
			
				if (!inqueue[edge.to])
				{
					q.push(edge.to);
					inqueue[edge.to] = true;
					++counts[edge.to];
					
					if (N < counts[edge.to])
					{
						return true; // 負閉路あり
					}
				}
			}
		}
	}

	return false;
}

// ベルマンフォード法 (1.5 SPFA + 最短経路の再構築)
// 負閉路が存在する場合 true を返す
// 負閉路が存在しない場合, 頂点 startIndex から頂点 targetIndex の最短経路を path に格納する
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
bool SPFA(const Graph& graph, std::vector<long long>& distances, int startIndex, int targetIndex, std::vector<int>& path)
{
	const size_t N = distances.size();
	std::vector<int> counts(N);
	std::vector<bool> inqueue(N);
	std::queue<int> q;

	// 直前の頂点を記録する配列
	std::vector<int> p(N, -1);

	distances[startIndex] = 0;
	q.push(startIndex);
	inqueue[startIndex] = true;

	while (!q.empty())
	{
		const int from = q.front(); q.pop();
		inqueue[from] = false;

		for (const auto& edge : graph[from])
		{
			// to までの新しい距離
			const long long d = (distances[from] + edge.cost);

			// d が現在の記録より小さければ更新
			if (d < distances[edge.to])
			{
				distances[edge.to] = d;
				p[edge.to] = from;
			
				if (!inqueue[edge.to])
				{
					q.push(edge.to);
					inqueue[edge.to] = true;
					++counts[edge.to];
					
					if (N < counts[edge.to])
					{
						return true; // 負閉路あり
					}
				}
			}
		}
	}

	if (distances[targetIndex] != INF) // 頂点 targetIndex に到達不可の場合は最短経路無し
	{
		// 経路を再構築
		for (int i = targetIndex; i != -1; i = p[i])
		{
			path.push_back(i);
		}

		std::reverse(path.begin(), path.end());
	}

	return false;
}


int n_node;
vector<long long> dist(n_node, INF);
vector<int> edges; // 1~3 辺のリスト
vector<vector<edge>> graph(n_node); // 4, 5 隣接リスト
vector<int> path;

int main(){
    return 0;
}