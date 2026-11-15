#include <iostream>

using namespace std;

#define MOD 10007

int n;

int main() {
    cin >> n;

    int dp[n + 1]{};
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3;i <= n;i++){
        dp[i] = ((dp[i - 1] % MOD) + (dp[i - 2] % MOD)) % MOD;
    }
    cout << dp[n];

    return 0;
}
