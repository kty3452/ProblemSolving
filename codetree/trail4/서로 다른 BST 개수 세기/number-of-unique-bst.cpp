#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    int dp[n + 1]{};

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3;i <= n;i++){
        for(int j = 0;j < i;j++){
            dp[i] += (dp[i - j - 1] * dp[j]);
        }
    }

    cout << dp[n];

    return 0;
}
