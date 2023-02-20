#include <bits/stdc++.h>
using namespace std;
#define pic pair<int, char>

int n;
pic A[100009];
map<int, queue<char>> pool;

int partition(pic A[], int p, int r){
    int x = A[r].first;
    int i = p - 1;

    for(int j=p;j<r;j++){
        if(A[j].first<=x){
            i++;
            pic tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    pic tmp2 = A[i+1];
    A[i+1]= A[r];
    A[r] = tmp2;
    return i+1;
}

void quickSort(pic A[], int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

// merge sortの結果と比較する手もある!
bool isStable(pic A[], map<int, queue<char>> pool){
    for(int i=0;i<n;i++){
        if(A[i].second == pool[A[i].first].front()){
            pool[A[i].first].pop();
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n;
    int a;
    char k;
    for(int i=0;i<n;i++){
        cin >> A[i].second >> A[i].first;
        pool[A[i].first].push(A[i].second);
    }

    // int q = partition(A, 0, n-1);
    quickSort(A, 0, n-1);

    if(isStable(A, pool)) cout << "Stable" << endl;
    else cout << "Not stable" << endl;

    for(int i=0;i<n;i++){
        cout << A[i].second << " " << A[i].first << endl;
    }

    return 0;
}