#include <iostream>
#include <vector>
using namespace std;

template<class Abel> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]]; // 累積和をとる
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x); // 経路圧縮
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // weight(y) - weight(x) = w となるように merge する (y=x+w)
    bool merge(int x, int y, Abel w) {
        // x と y それぞれについて、 root との重み差分を補正
        w += weight(x); w -= weight(y);
        // x と y の root へ (x と y が既につながっていたら false を返すようにした)
        x = root(x); y = root(y);
        if (x == y) return false;
        // rank[x] >= rank[y] となるように x と y を swap (それに合わせて w も符号反転します)
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        // y (のroot) を x (のroot) の下にくっつける
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        // x が y の親になるので、x と y の差分を diff_weight[y] に記録
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};