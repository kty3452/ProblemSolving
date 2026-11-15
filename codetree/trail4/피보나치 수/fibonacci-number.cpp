#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    int fibo[46];
    fibo[1] = 1;
    fibo[2] = 1;

    for(int i = 3;i <= N;i++){
        fibo[i] = fibo[i - 2] + fibo[i - 1];
    }

    cout << fibo[N];


    return 0;
}
