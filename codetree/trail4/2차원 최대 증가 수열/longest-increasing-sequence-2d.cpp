#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int grid[50][50];
int dp[50][50];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0;i < n;i++){
        fill(dp[i], dp[i] + m, INT_MIN);
    }
    dp[0][0] = 1;

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if(dp[i][j] == INT_MIN) continue;
            for (int r = i + 1; r < n; r++) {
                for (int c = j + 1; c < m; c++) {
                    if(grid[i][j] < grid[r][c]){
                        dp[r][c] = max(dp[i][j] + 1, dp[r][c]);
                    }
                }
            }
        }
    }
    int max_num = INT_MIN;

    for(int i = 0;i < n;i++){
        max_num = max(max_num, *max_element(dp[i], dp[i] + m));
    }
    cout << max_num;

    return 0;
}
