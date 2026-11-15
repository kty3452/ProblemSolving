#include <iostream>
#include <algorithm>
using namespace std;

int n;
int grid[101][101];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int dp[101][101]{};

    for(int i = 0;i < n;i++){
        dp[1][n - i - 1] = grid[1][n - i - 1] + dp[1][n - i];
        dp[i + 1][n - 1] = grid[i + 1][n - 1] + dp[i][n - 1];
    }

    for(int i = 2;i <= n;i++){
        for(int j = n - 2;j >= 0;j--){
            dp[i][j] += min(dp[i - 1][j] + grid[i][j], dp[i][j + 1] + grid[i][j]);
        }
    }

    cout << dp[n][0];


    return 0;
}
