#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define STANDARD_SIZE 4

int n;
int grid[100][100];
int block_size;
int max_size = 0;
vector<vector<bool>> visited;

bool InRange(int r, int c){
    return r >= 0 && c >= 0 && r < n && c < n;
}

bool CanGo(int r, int c, int nr, int nc){
    return !visited[nr][nc] && grid[r][c] == grid[nr][nc];
}

void DFS(int r, int c){
    static int dr[4] = {0, 0, 1, -1};
    static int dc[4] = {1, -1, 0, 0};
    for(int i = 0;i < 4;i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(InRange(nr, nc) && CanGo(r, c, nr, nc)){
            visited[nr][nc] = true;
            block_size++;
            DFS(nr, nc);
        }
    }
}

int main() {
    cin >> n;
    int block_cnt = 0;
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int r = 0;r < n;r++){
        for(int c = 0;c < n;c++){
            if(!visited[r][c]){
                block_size = 1;
                visited[r][c] = true;
                DFS(r, c);
                max_size = max(block_size, max_size);
                if(block_size >= STANDARD_SIZE) block_cnt++;
            }
        }
    }

    cout << block_cnt << " " << max_size;

    // Please write your code here.

    return 0;
}
