#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int grid[500][500];
int dp[500][500]{};
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
vector<int> num;

bool CanGo(int r, int c, int nr, int nc){
    return dp[nr][nc] < dp[r][c] + 1 && grid[nr][nc] > grid[r][c];
}

bool InRange(int r, int c){
    return r >= 0 && r < n & c >= 0 && c < n;
}

int FindIdx(int a, int left, int right){
    int mid = (left + right) / 2;
    while(left <= right){
        if(num[mid] > a){
            right = mid - 1;
        }
        else if(num[mid] < a){
            left = mid + 1;
        }
        else{
            break;
        }
        mid = (left + right) / 2;
    }
    return mid;
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            num.push_back(grid[i][j]);
            dp[i][j] = 1;
        }
    }

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    vector<vector<pair<int, int>>> coor(num.size(), vector<pair<int, int>>());
    int answer = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int idx = FindIdx(grid[i][j], 0, num.size() - 1);
            coor[idx].push_back({i, j});
        }
    }

    for(int i = 0;i < coor.size();i++){
        for(int j = 0;j < coor[i].size();j++){
            auto [r, c] = coor[i][j];
            for(int i = 0;i < 4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(InRange(nr, nc) && CanGo(r, c, nr, nc)){
                    dp[nr][nc] = dp[r][c] + 1;
                    answer = max(dp[nr][nc], answer);
                }
            }
        }
    }



    cout << answer;

    return 0;
}

