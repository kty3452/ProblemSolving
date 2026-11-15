#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[101][101];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    int dp[101][101]{};
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            dp[i][j] += max(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
        }
    }
    cout << dp[n][n];


    // Please write your code here.

    return 0;
}
