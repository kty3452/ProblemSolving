/*
11:04 시작
각 격자 값마다 좌표를 미리 구해놓고 시작 위치에서 갈 수 있는 좌표인지 확인하면 될 듯.
11:09 일시 정지.
11:31 다시 시작.
11:?? 일시 정지.
12:42 다시 시작.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Coordinate{
    int r = 0;
    int c = 0;
};

int n, k;
int grid[100][100];
int r, c;
vector<vector<bool>> visited;
queue<Coordinate> q;
vector<vector<Coordinate>> num;

Coordinate CalNext(int r, int c){
    int start = grid[r][c] - 1;
    for(int i = start;i >= 1;i--){
        for(int j = 0;j < num[i].size();j++){
            auto [nr, nc] = num[i][j];
            if(visited[nr][nc]) return Coordinate{nr, nc};
        }
    }
    return Coordinate{r, c};
}

void Push(int r, int c){
    q.push({r, c});
    visited[r][c] = true;
}

bool InRange(int r, int c){
    return r >= 0 && r < n && c >= 0 && c < n;
}

bool CanGo(int start_r, int start_c, int r, int c){
    return !visited[r][c] && grid[start_r][start_c] > grid[r][c];
}

void BFS(int start_r, int start_c){
    static int dr[4] = {0, 0, 1, -1};
    static int dc[4] = {1, -1, 0, 0};

    q.push({start_r, start_c});
    visited[start_r][start_c] = true;

    while(!q.empty()){
        auto [lr, lc] = q.front();
        q.pop();

        for(int i = 0;i < 4;i++){
            int nr = lr + dr[i];
            int nc = lc + dc[i];
            if(InRange(nr, nc) && CanGo(start_r, start_c, nr, nc)){
                Push(nr, nc);
            }
        }
    }
}

int main() {
    cin >> n >> k;

    num.resize(101, vector<Coordinate>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            num[grid[i][j]].push_back({i, j});
        }
    }

    cin >> r >> c;
    r--;
    c--;

    while(k--){
        visited.assign(n, vector<bool>(n, false));
        BFS(r, c);
        auto [a, b] = CalNext(r, c);
        r = a;
        c = b;
    }

    cout << r + 1 << " " << c + 1;

    return 0;
}
