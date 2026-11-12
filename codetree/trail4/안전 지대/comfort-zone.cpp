#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int max_k = 0;
int now_k = 0;
int grid[50][50];
vector<vector<bool>> visited;

bool InRange(int r, int c){
    return r >= 0 && c >= 0 && r < N && c < M;
}

bool CanGo(int r, int c){
    return grid[r][c] - now_k > 0 && !visited[r][c];
}

void DFS(int r, int c){
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    for(int i = 0;i < 4;i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(InRange(nr, nc) && CanGo(nr, nc)){
            visited[nr][nc] = true;
            DFS(nr, nc);
        }
    }   
}

int main() {
    cin >> N >> M;
    int ans_cnt = 0;
    int ans_k = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            max_k = max(max_k, grid[i][j]);
        }
    }

    visited.resize(N, vector<bool>(M, false));

    for(int k = 1;k < max_k;k++){
        now_k = k;
        visited.assign(N, vector<bool>(M, false));
        int cnt = 0;
        for(int i = 0;i < N;i++){
            for(int j = 0;j < M;j++){
                if(CanGo(i, j)){
                    visited[i][j] = true;
                    DFS(i, j);
                    cnt++;
                }
            }
        }
        if(cnt > ans_cnt){
            ans_cnt = cnt;
            ans_k = now_k;
        }
    }

    cout << ans_k << " " << ans_cnt;

    return 0;
}
