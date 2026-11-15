/*
    1x2 하나만 추가한 경우,
    2x1 두 개를 추가한 경우,
    1x1 하나를 추가한 경우,
    이렇게 3개 인거 같은데..
*/

#include <iostream>

using namespace std;

#define MOD 1000000007
int n;


int main() {
    cin >> n;

    long long dp[n + 2][3]{};
    dp[0][0] = 1; // 완전체
    dp[0][1] = 1; // 위에 하나만 추가한다.
    dp[0][2] = 1; // 밑에 하나만 추가한다.
    dp[1][0] = 2;
    dp[1][1] = 1;
    dp[1][2] = 1;

    for(int i = 2;i <= n + 1;i++){
        dp[i][0] = ((dp[i - 1][0] % MOD) + (dp[i - 1][0] % MOD) + (dp[i - 2][0] % MOD) + (dp[i - 1][1] % MOD) + (dp[i - 1][2] % MOD)) % MOD;
        dp[i][1] = ((dp[i - 1][0] % MOD) + (dp[i - 1][2] % MOD)) % MOD;
        dp[i][2] = ((dp[i - 1][0] % MOD) + (dp[i - 1][1] % MOD)) % MOD;
    }

    cout << dp[n][0];

    return 0;
}
