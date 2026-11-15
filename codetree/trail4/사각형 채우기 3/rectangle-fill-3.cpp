/*
    1x2 하나만 추가한 경우,
    2x1 두 개를 추가한 경우,
    1x1 하나를 추가한 경우,
    이렇게 3개 인거 같은데..
*/

#include <iostream>
#include <array>
#include <vector>

using namespace std;
using Matrix = array<array<long long, 3>, 3>;

#define MOD 1000000007
#define IDX 2
int n;

Matrix multiply(Matrix A, Matrix B){
    Matrix C = {0};
    for(int r = 0;r < 3;r++){
        for(int c = 0;c < 3;c++){
            for(int k = 0;k < 3;k++){
                C[r][c] = (C[r][c] + A[r][k] * B[k][c]) % MOD; 
            }
        }
    }
    return C;
}

Matrix power(Matrix base, int exponent){
    Matrix result = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};

    while(exponent > 0){
        if(exponent % 2 == 1)
            result = multiply(result, base);


        base = multiply(base, base);
        exponent /= 2;
    }

    return result;
}

int main(){
    cin >> n;
    Matrix M = {{{2, 1, 2}, {1, 0, 0}, {1, 0, 1}}};
    vector<long long> v = {2, 1, 1};
    vector<long long> answer(3, 0);

    M = power(M, n - 1);

    for(int r = 0;r < 3;r++){
        for(int c = 0;c < 3;c++){
            answer[r] = (answer[r] + M[r][c] * v[c]) % MOD;
        }
    }

    cout << answer[0];

    return 0;
}


// int main() {
//     cin >> n;

//     long long dp[3][3]{};
//     dp[0][0] = 1; // 완전체
//     dp[1][0] = 2;
//     dp[1][1] = 1; // 위에 하나만 추가한 경우.
//     dp[1][2] = 1; // 밑에 하나만 추가한 경우.
//     dp[2][0] = 2;

//     for(int i = 2;i <= n;i++){
//         dp[IDX][0] = ((dp[IDX - 1][0]) + (dp[IDX - 1][0]) + (dp[IDX - 2][0]) + (dp[IDX - 1][1]) + (dp[IDX - 1][2])) % MOD;
//         // 2x1 하나 추가하거나, 1x1 두 개 추가하거나, 1x2 두 개 추가하거나, 1x2 + 1x1을 위아래 각각 추가하거나   
//         dp[IDX][1] = ((dp[IDX - 1][0]) + (dp[IDX - 1][2])) % MOD;
//         // 하나만 튀어 나오는 경우는 완전체에서 1x1 하나 추가하거나, 하나 빠진 놈에서 1x2 추가하거나.
//         dp[IDX][2] = ((dp[IDX - 1][0]) + (dp[IDX - 1][1])) % MOD;
//         // 하나만 튀어 나오는 경우는 완전체에서 1x1 하나 추가하거나, 하나 빠진 놈에서 1x2 추가하거나.

//         for(int j = 0;j < 2;j++){
//             dp[j][0] = dp[j + 1][0];
//             dp[j][1] = dp[j + 1][1];
//             dp[j][2] = dp[j + 1][2];
//         }
//     }

//     cout << dp[2][0];

//     return 0;
// }
