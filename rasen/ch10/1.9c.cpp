#include <bits/stdc++.h>
using namespace std;
#define INF (1<<10)

int n = 0, x;
int T[2000009];

int get_parent(int x){
    return x / 2;
}

int get_left(int x){
    return 2 * x;
}
int get_right(int x){
    return 2 * x + 1;
}

void maxHeapify(int i){
    int l = get_left(i);
    int r = get_right(i);
    int largest;
    if(l<=n && T[i]<T[l]){
        largest = l;
    }else{
        largest = i;
    }
    if(r<=n && T[largest]<T[r]){
        largest = r;
    }

    if(largest != i){
        swap(T[largest], T[i]);
        maxHeapify(largest);
    }
}

void buildMaxHeap(){
    for(int i=n/2;i>0;i--){
        maxHeapify(i);
    }
}

void heapIncreaseKey(int i, int key){
    if(key < T[i]) return;

    T[i] = key;
    while(i>1 && T[get_parent(i)] < T[i]){
        swap(T[i], T[get_parent(i)]);
        i = get_parent(i);
    }
}

void insert(int key){
    n++;
    T[n] = -INF;
    heapIncreaseKey(n, key);
}

int heapExtractMax(){
    if(n<1) return -1;

    int mx = T[1];
    T[1] = T[n];
    n--;
    maxHeapify(1);
    return mx;
}

void print(int x){
    cout << "node " << x;
    cout << ": key = " << T[x] << ", ";
    if(get_parent(x) > 0) cout << "parent key = " << T[get_parent(x)] << ", ";
    if(get_left(x) <= n) cout << "left key = " << T[get_left(x)] << ", ";
    if(get_right(x) <= n) cout << "right key = " << T[get_right(x)] << ", ";
    cout << endl;
}

int main(){
    string msg;
    cin >> msg;
    
    while(msg != "end"){
        if(msg == "insert"){
            cin >> x;
            insert(x);
        }else{
            int mx = heapExtractMax();
            cout << mx << endl;
        }
        cin >> msg;
    }
    return 0;
}