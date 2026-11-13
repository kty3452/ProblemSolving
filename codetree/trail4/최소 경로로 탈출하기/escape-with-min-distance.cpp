#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int n, m;
int a[100][100];

queue<pair<int, int>> q;
int visited[100][100]{};

void Push(int r, int c, int nr, int nc){
    visited[nr][nc] = visited[r][c] + 1;
    q.push({nr, nc});
}

bool CanGo(int r, int c){
    return !visited[r][c] && a[r][c];
}

bool InRange(int r, int c){
    return r >= 0 && c >= 0 && r < n && c < m;
}

void BFS(){
    static int dr[4] = {0, 0, -1, 1};
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
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    visited[0][0] = 1;
    q.push({0, 0});
    BFS();

    cout << visited[n - 1][m - 1] - 1;

    return 0;
}
