#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, k, m;
vector<vector<int>> grid;
vector<pair<int, int>> stoneRC;
vector<vector<bool>> visited_BFS;
int r[10000], c[10000];
int answer = 0;
queue<pair<int, int>> q;

bool InRange(int r, int c){
    return r >= 0 && c >= 0 && r < n && c < n;
}

bool CanGo(int r, int c){
    return !visited_BFS[r][c] && !grid[r][c];
}
void Push(int r, int c){
    visited_BFS[r][c] = true;
    q.push({r, c});
}

int BFS(){
    static int dr[4] = {0, 0, 1, -1};
    static int dc[4] = {1, -1, 0, 0};
    visited_BFS.assign(n, vector<bool>(n, false));
    for(int i = 0;i < k;i++){
        Push(r[i], c[i]);
    }
    int cnt = k;

    while(!q.empty()){
        auto[r, c] = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(InRange(nr, nc) && CanGo(nr, nc)){
                Push(nr, nc);
                cnt++;
            }
        }
    }
    return cnt;
}

void Backtracking(int start, int depth){
    static vector<pair<int, int>> v;
    if(depth == m){
        for(int i = 0;i < m;i++){
            auto [r, c] = v[i];
            grid[r][c] = 0;
        }
        answer = max(BFS(), answer);
        for(int i = 0;i < m;i++){
            auto [r, c] = v[i];
            grid[r][c] = 1;
        }
        return;
   }
    for(int i = start;i < stoneRC.size();i++){
        auto [r, c] = stoneRC[i];
        v.push_back({r, c});
        Backtracking(i + 1, depth + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> k >> m;
    grid.resize(100, vector<int>(100, 0));
    visited_BFS.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
            if(grid[i][j]) stoneRC.push_back({i, j});
        }

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }

    Backtracking(0, 0);

    cout << answer;
    

    return 0;
}
