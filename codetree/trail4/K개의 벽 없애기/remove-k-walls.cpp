/*
23:18 시작

*/

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int n, k;
int grid[100][100];
int r1, c1, r2, c2;
int min_num = INT_MAX;
queue<pair<int ,int>> q;
int visited[100][100]{};
vector<pair<int, int>> wall;

void Push(int r, int c, int nr, int nc){
    visited[nr][nc] = visited[r][c] + 1;
    q.push({nr, nc});
}

bool InRange(int r, int c){
    return r >= 0 && c >= 0 && r < n && c < n; 
}

bool CanGo(int r, int c){
    return !visited[r][c] && !grid[r][c];
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

void Backtracking(int start, int depth, vector<pair<int, int>> v){
    if(depth == k){
        for(auto [r, c] : v) grid[r][c] = 0;
        memset(visited, 0, sizeof(visited));
        Push(r1, c1, r1, c1);
        BFS();
        if(visited[r2][c2]) min_num = min(min_num, visited[r2][c2]);
        for(auto [r, c] : v) grid[r][c] = 1;
        return;
    }
    for(int i = start;i < wall.size();i++){
        v.push_back({wall[i]});
        Backtracking(i + 1, depth + 1, v);
        v.pop_back();
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j]) wall.push_back({i, j});
        }
    }

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;

    vector<pair<int, int>> v;
    Backtracking(0, 0, v);

    
    if(min_num == INT_MAX) cout << - 1;
    else cout << min_num - 1;

    // Please write your code here.

    return 0;
}
