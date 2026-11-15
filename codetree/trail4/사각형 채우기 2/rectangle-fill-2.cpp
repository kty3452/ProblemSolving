#include <iostream>
#include <array>
#include <vector>

using namespace std;

#define MOD 10007;

int n;

using Matrix = array<array<long long, 2>, 2>;

Matrix Multiply(Matrix A, Matrix B){
    Matrix C = {};
    for(int r = 0;r < 2;r++){
        for(int c = 0;c < 2;c++){
            for(int t = 0;t < 2;t++){
                C[r][c] = (C[r][c] + A[r][t] * B[t][c]) % MOD;    
            }
        }
    }
    return C;
}

Matrix Power(Matrix base, int exponent){
    Matrix result = {{{1, 0}, {0, 1}}};

    while(exponent > 0){

        if(exponent % 2 == 1) result = Multiply(result, base);

        base = Multiply(base, base);
        exponent /= 2;
    }

    return result;
}

int main(){
    cin >> n;
    Matrix M = {{{1, 2}, {1, 0}}};
    vector<long long> v = {1, 1};
    vector<long long> answer(2, 0);

    M = Power(M, n - 1);

    for(int r = 0;r < 2;r++){
        for(int c = 0;c < 2;c++){
            answer[r] = (answer[r] + M[r][c] * v[c]) % MOD;
        }
    }

    cout << answer[0];

    return 0;
}


// int main() {
//     cin >> n;

//     long long dp[1001];
//     dp[0] = 1;
//     dp[1] = 1;

//     for(int i = 2;i <= n;i++){
//         dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD;
//     }

//     cout << dp[n];

//     return 0;
// }
