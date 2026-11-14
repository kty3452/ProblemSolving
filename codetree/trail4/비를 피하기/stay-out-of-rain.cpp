#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int n, h, m;
int grid[100][100];
int visited[100][100]{};
queue<pair<int, int>> q;

void Push(int r, int c, int nr, int nc){
    q.push({nr, nc});
    visited[nr][nc] = visited[r][c] + 1;
}

bool InRange(int r, int c){
    return r >= 0 && c >= 0 && r < n && c < n;
}

bool CanGo(int r, int c){
    return !visited[r][c] && grid[r][c] != 1;
}

void BFS(){
    static int dr[4] = {0, 0, 1, -1};
    static int dc[4] = {1, -1, 0, 0};

    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(InRange(nr, nc) && CanGo(nr, nc)){
                Push(r, c, nr, nc);
            }
        }
    }
}

int main() {
    cin >> n >> h >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 3){
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    BFS();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 2) cout << visited[i][j] - 1 << " ";
            else cout << 0 << " ";
        }
        cout << "\n";
    }


    // Please write your code here.

    return 0;
}
