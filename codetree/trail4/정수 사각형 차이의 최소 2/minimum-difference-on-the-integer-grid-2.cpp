#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int grid[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<vector<pair<int, int>>>> dp(n, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(101, pair<int, int>(INT_MIN, INT_MAX))));
    dp[0][0][grid[0][0]] = make_pair(grid[0][0], grid[0][0]);

    
    for (int i = 1; i < n; i++) {
        for(int j = 1;j <= 100;j++){
            if(dp[0][i - 1][j].first != INT_MIN){
                auto [lmax, lmin] = make_pair(max(dp[0][i - 1][j].first, grid[0][i]), min(dp[0][i - 1][j].second, grid[0][i]));
                dp[0][i][lmin] = make_pair(lmax, lmin);
            }
            if(dp[i - 1][0][j].first != INT_MIN){
                auto [umax, umin] = make_pair(max(dp[i - 1][0][j].first, grid[i][0]), min(dp[i - 1][0][j].second, grid[i][0]));
                dp[i][0][umin] = make_pair(umax, umin);
            }
        }
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            vector<pair<int, int>> v;
            for(int k = 1;k <= 100;k++){
                if(dp[i - 1][j][k].first != INT_MIN) v.push_back(make_pair(max(grid[i][j], dp[i - 1][j][k].first), min(grid[i][j], dp[i - 1][j][k].second)));
                if(dp[i][j - 1][k].first != INT_MIN) v.push_back(make_pair(max(grid[i][j], dp[i][j - 1][k].first), min(grid[i][j], dp[i][j - 1][k].second)));
            }
            for(int k = 0;k < v.size();k++){
                if(dp[i][j][v[k].second].first == INT_MIN){
                    dp[i][j][v[k].second] = v[k];
                }
                else{
                    dp[i][j][v[k].second].first = min(dp[i][j][v[k].second].first, v[k].first);
                }
            }
        }
    }

    int min_num = INT_MAX;
    for(int i = 1;i <= 100;i++){
        if(dp[n - 1][n - 1][i].first != INT_MIN)
            min_num = min(dp[n - 1][n - 1][i].first - dp[n - 1][n - 1][i].second, min_num);
    }

    cout << min_num;

    return 0;
}

