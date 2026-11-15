#include <iostream>

using namespace std;

#define MOD 10007;

int n;


int main() {
    cin >> n;

    long long dp[1001];
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2;i <= n;i++){
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD;
    }

    cout << dp[n];

    return 0;
}
