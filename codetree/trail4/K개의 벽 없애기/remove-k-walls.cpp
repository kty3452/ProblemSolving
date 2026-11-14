/*
23:18 시작
23:40 완료
23:46 3차원 visited 시작
*/

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include <cstring>
#include <tuple>

using namespace std;

int n, k;
int grid[100][100];
int r1, c1, r2, c2;
int min_num = INT_MAX;
queue<tuple<int, int, int>> q;
vector<vector<vector<int>>> visited;

void Push(int r, int c, int nr, int nc, int now_wall){
    visited[nr][nc][now_wall - grid[nr][nc]] = visited[r][c][now_wall] + 1;
    q.push({nr, nc, now_wall - grid[nr][nc]});
}

bool InRange(int r, int c){
    return r >= 0 && c >= 0 && r < n && c < n; 
}


bool CanGo(int r, int c, int now_wall){
    return !visited[r][c][now_wall] && now_wall - grid[r][c] >= 0;
}


void BFS(){
    static int dr[4] = {0, 0, 1, -1};
    static int dc[4] = {1, -1, 0, 0};

    while(!q.empty()){
        auto [r, c, k] = q.front();
        q.pop();

        for(int i = 0;i < 4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(InRange(nr, nc) && CanGo(nr, nc, k)){
                Push(r, c, nr, nc, k);
            }
        }
    }

}

int main() {
    cin >> n >> k;
    visited.resize(n, vector<vector<int>>(n, vector<int>(k + 1, 0)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;

    visited[r1][c1][k] = 1;
    q.push({r1, c1, k});

    BFS();

    int min_num = INT_MAX;
    for(int i = 0;i <= k;i++){
        if(visited[r2][c2][i] != 0) min_num = min(visited[r2][c2][i] - 1, min_num);
    }
    if(min_num == INT_MAX) cout << -1;
    else cout << min_num;


    return 0;
}
