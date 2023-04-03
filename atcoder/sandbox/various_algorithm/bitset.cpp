#include <bits/stdc++.h>
using namespace std;

// {0, 1, ..., n-1}
// 0を下位ビット(1ビット目)とする
template<class Tm>
class BitSet{
public:
    int siz;
    BitSet(int siz=0): siz(siz){}
    // sizeの準備
    void set_size(int sz){
        siz = sz;
    }
    // 空集合
    Tm empty(){
        return (Tm)0;
    }
    // n個全てからなる集合
    Tm all(){
        return (((Tm)(1)<<siz) - 1);
    }
    // Sにi(番目)が含まれるか
    bool include(Tm S, int i){
        return (S>>i) & (Tm)(1);
    }
    // 集合Sに要素iを加える S∨{i}
    Tm add_set(Tm S, int i){
        return S | ((Tm)(1)<<i);
    }
    // 集合Sから要素iを取り除く S\{i}
    Tm remove_set(Tm S, int i){
        return S & ~((Tm)(1)<<i);
    }
    // 集合SとTの和集合
    Tm or_set(Tm S, Tm T){
        return S | T;
    }
    // 集合SとTの積集合
    Tm and_set(Tm S, Tm T){
        return S & T;
    }
    // 文字列からint生成("01011"->11)
    Tm str2int(string s){
        Tm S = (Tm)0;
        for(int i=0;i<(int)s.size();i++){
            // if(i>=(int)s.size()) break;
            S += (s[s.size()-i-1]-'0')<<i;
        }
        return S;
    }
};

int main(){
    using T = int;
    int N = 5;
    BitSet<T> bs(N);

    // 文字列から集合(数値)を生成
    cout << bs.str2int("0010101") << endl;

    // bit全探索
    for(T i=0;i<=bs.all();i++){
        // 各要素についての処理
        cout << i << endl;
        for(int j=0;j<N;j++){
            if(i&(1<<j)){
                // 処理
            }
        }
    }

    // Sの部分集合についての探索
    T S = 10;
    T sub = S;
    do{
        // 部分集合に対する処理
        cout << sub << endl;
        for(int i=0;i<N;i++){
            if(sub&(1<<i)){
                // 処理
            }
        }

        sub = (sub - 1) & S;
    }while(sub != S); // 0の次は-1 & S = Sになる
    
    // N個からK個選ぶ部分集合についての探索
    int K = 3;
    T comb = (1LL<<K) - 1; // 下位Kビットの要素{0, 1, ..., K-1}を選択したものからスタート
    while(comb <= bs.all()){
        // ここで組み合わせに対して処理をする
        cout << comb << endl;
        for(int i=0;i<N;i++){
            if(comb&(1<<i)){
                // 処理
            }
        }

        T x = comb & -comb; // 最下位の1のビットを独立させる
        T y = comb + x; // 最下位の1の連続している区間を0にする(1つ下位から上位に移動)
        T z = comb & ~y; // 最下位の1の連続している区間を取り出す
        T w = (z / x) >> 1; // 右側の0をなくしてさらに右に1ビットシフト(上位に移動した1つを取り除く)
        comb = w | y; // 次の要素Kの部分集合
    }
    return 0;
}