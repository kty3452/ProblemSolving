#include <iostream>

using namespace std;

int n;
int dp[1001]{};

int main() {
    cin >> n;

    dp[0] = 1;
    dp[2] = 1;

    for(int i = 3;i <= n;i++){
        dp[i] = ((dp[i - 2] % 10007) + (dp[i - 3] % 10007)) % 10007;
    }

    cout << dp[n];

    return 0;
}