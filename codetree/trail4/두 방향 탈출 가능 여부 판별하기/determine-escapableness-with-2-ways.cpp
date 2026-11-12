#include <iostream>
#include <vector>

using namespace std;

int n, m;
int grid[100][100];
vector<vector<bool>> visited;
bool answer = false;

bool InRange(int nr, int nc){
    return nr >= 0 && nc >= 0 && nr < n && nc < m;
}

bool CanGo(int nr, int nc){
    return InRange(nr, nc) && !visited[nr][nc] && grid[nr][nc];
}

void DFS(int r, int c){
    static int dr[2] = {1, 0};
    static int dc[2] = {0, 1};

    for(int i = 0;i <= 1;i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(CanGo(nr, nc)){
            visited[nr][nc] = true;
            DFS(nr, nc);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    visited.resize(n, vector<bool>(n, false));

    DFS(0, 0);

    cout << visited[n - 1][m - 1];

    return 0;
}
