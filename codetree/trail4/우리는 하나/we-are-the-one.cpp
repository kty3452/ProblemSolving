#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int n, k, u, d;
int grid[8][8];
vector<vector<bool>> visited;
queue<pair<int, int>> q;
int answer = 0;

bool CanGo(int r, int c, int nr, int nc){
    return !visited[nr][nc] && abs(grid[nr][nc] - grid[r][c]) >= u && abs(grid[nr][nc] - grid[r][c]) <= d ;
}

bool InRange(int r, int c){
    return r >= 0 && c >= 0 && r < n && c < n;
}


void Push(int r, int c){
    visited[r][c] = true;
    q.push({r, c});
}

int BFS(){
    static int dr[4] = {0, 0, 1, -1};
    static int dc[4] = {1, -1, 0, 0};
    int cnt = k;

    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();

        for(int i = 0;i < 4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(InRange(nr, nc) && CanGo(r, c, nr, nc)){
                Push(nr, nc);
                cnt++;
            }
        }
    }
    return cnt;
}

void Backtracking(int depth, int start){
    static vector<pair<int, int>> city;
    if(depth == k){
        visited.assign(n, vector<bool>(n, false));
        for(auto [r, c] : city){
            Push(r, c);
        }
        answer = max(answer, BFS());
        return;
    }
    for(int i = start;i < n * n;i++){
        int r = i / n;
        int c = i % n;
        city.push_back({r, c});
        Backtracking(depth + 1, i + 1);
        city.pop_back();
    }
}

int main() {
    cin >> n >> k >> u >> d;
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Backtracking(0, 0);

    cout << answer;

    return 0;
}
