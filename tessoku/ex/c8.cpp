#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string S[1009]; int T[1009];

// 当選番号が A2 のとき、A1 は何等かを返す
int Hantei(string A1, string A2) {
	int Diff = 0;
	for (int i = 0; i < 4; i++) {
		if (A1[i] != A2[i]) Diff += 1;
	}
	if (Diff == 0) return 1; // 全く同じとき 1 等
	if (Diff == 1) return 2; // 桁が 1 つだけ違うとき 2 等
	return 3;
}

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> S[i] >> T[i];

	// 全探索
	vector<string> Answer;
	for (int num = 0; num <= 9999; num++) {
		// 整数 num を 4 桁の文字列に置き換える
		string ID = to_string(num);
		while (ID.size() < 4) ID = "0" + ID;

		// すべての情報が正しいかどうかを確認
		bool flag = true;
		for (int i = 1; i <= N; i++) {
			if (Hantei(S[i], ID) != T[i]) flag = false;
		}


		// もしすべての情報が正しかった場合
		if (flag == true) {
			Answer.push_back(ID);
		}
	}

	// 出力
	if (Answer.size() != 1) {
		cout << "Can't Solve" << endl;
	}
	else {
		cout << Answer[0] << endl;
	}
	return 0;
}

// #include <bits/stdc++.h>

// #define rep(i,s,n) for(int i = s; i < n; i++)
// #define ll long long
// #define P pair<ll, ll>

// using namespace std;

// int N, T[109];
// string S[109];
// vector<string> v[4];

// string solve(){
//     if(v[1].size()>0){
//         return v[1][0];
//     }else{
//         string ans = "0000";
//         bool kakutei[4] = {false, false, false, false};
//         if(v[2].size()<2){
//             return "Can't Solve";
//         }else{
//             set<char> kouho[4];
//             rep(i, 0, v[2].size()){
//                 rep(j, i+1, v[2].size()){
//                     rep(k, 0, 4){
//                         if(v[2][i][k] == v[2][j][k]){
//                             ans[k] = v[2][i][k];
//                             kakutei[k] = true;
//                             kouho[k].erase(v[2][i][k]);
//                         }else{
//                             kouho[k].insert(v[2][i][k]);
//                             kouho[k].insert(v[2][j][k]);
//                         }
//                     }
//                 }
//             }
//             rep(i, 0, v[3].size()){
//                 rep(k, 0, 4){
//                     kouho[k].erase(v[3][i][k]);
//                 }
//             }
//             rep(k, 0, 4){
//                 if(!kakutei[k] && kouho[k].size()==1){
//                     auto itr = kouho[k].begin();
//                     kakutei[k] = true;
//                     ans[k] = *itr;
//                 }
//             }

//             if(kakutei[0] && kakutei[1] && kakutei[2] && kakutei[3]) return ans;
//             else return "Can't Solve";

//         }

//     }
// }

// int main(){
//     cin >> N;
//     rep(i, 1, N+1){
//         cin >> S[i] >> T[i];
//         v[T[i]].push_back(S[i]);
//     }

//     cout << solve() << endl;
//     return 0;
// }