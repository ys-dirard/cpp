#include <iostream>
using namespace std;

int main () {
    int A, B;
    cin >> A >> B;
    for (int i = A; i <= B; i++) {
        if (100 % i == 0) {
            cout << "Yes" << endl;
            exit(0);
        }
    }
    cout << "No" << endl;
    return 0;
}