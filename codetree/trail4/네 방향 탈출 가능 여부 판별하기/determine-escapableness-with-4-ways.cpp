#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int a[100][100];
vector<vector<bool>> visited;
queue<pair<int, int>> q;

bool InRange(int r, int c){
    return r >= 0 && c >= 0 && r < n && c < m;
}

bool CanGo(int r, int c){
    return a[r][c] && !visited[r][c];
}

bool BFS(){
    static int dr[4] = {0, 0, 1, -1};
    static int dc[4] = {-1, 1, 0, 0};

    while(!q.empty()){
        auto[r, c] = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(InRange(nr, nc) && CanGo(nr, nc)){
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    return visited[n - 1][m - 1];

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    visited.resize(n, vector<bool>(m, false));
    q.push({0, 0});
    visited[0][0] = true;
    cout << BFS();


    return 0;
}
