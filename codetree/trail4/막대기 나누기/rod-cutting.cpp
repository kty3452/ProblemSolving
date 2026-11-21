#include <iostream>

using namespace std;

int n;
int profit[100];

int main() {
    cin >> n;
    int dp[101]{};
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    for(int j = 1;j <= n;j++){ // 현재 막대기 길이
        for(int i = 1;i <= j;i++){ // 현재 막대기 길이에서 빼고 싶은 길이
            dp[j] = max(dp[j], dp[j - i] + profit[i - 1]);
        }
    }

    cout << dp[n];

    return 0;
}
