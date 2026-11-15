#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, k;
int grid[100][100];
int visited[100][100]{};
queue<pair<int, int>> q;

void Push(int r, int c, int nr, int nc){
    visited[nr][nc] = visited[r][c] + 1;
    grid[nr][nc] = 2;
    q.push({nr, nc});
}

bool InRange(int r, int c){
    return r >= 0 && c >= 0 && r < n && c < n;
}

bool CanGo(int r, int c){
    return InRange(r, c) && grid[r][c] == 1; 
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
            
            if(CanGo(nr, nc)){
                Push(r, c, nr, nc);
            }
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 2){
                visited[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    BFS();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 1) cout << -2 << " ";
            else cout << visited[i][j] - 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
