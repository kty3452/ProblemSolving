#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int coin[1001];

int main() {
    cin >> n;
    int dp[1001][4]; // 각 계단을 올랐을 때, 1계단 오르는 것을 행한 횟수.
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
        fill(dp[i], dp[i] + 4, INT_MIN);
    }

    dp[0][0] = 0;
    dp[1][1] = coin[1];

    for(int floor = 2;floor <= n;floor++){
        dp[floor][0] = dp[floor - 2][0] + coin[floor];
        for(int j = 1;j < 4;j++){
            int just_before_floor = dp[floor - 1][j - 1] != INT_MIN ? dp[floor - 1][j - 1] + coin[floor] : INT_MIN;  
            int second_before_floor = dp[floor - 2][j] != INT_MIN ? dp[floor - 2][j] + coin[floor] : INT_MIN;
            dp[floor][j] = max(just_before_floor, second_before_floor);
        }
    }

    cout << *max_element(dp[n], dp[n] + 4);

    return 0;
}
