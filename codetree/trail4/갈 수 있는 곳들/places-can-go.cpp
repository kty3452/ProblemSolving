#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];
int total = 0;
queue<pair<int, int>> q;
vector<vector<bool>> visited;

bool CanGo(int r, int c){
    return !visited[r][c] && !grid[r][c];
}

bool InRange(int r, int c){
    return r >= 0 && c >= 0 && r < n && c < n;
}

void Push(int a, int b){
    visited[a][b] = true;
    q.push({a, b});
    total++;
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
                Push(nr, nc);
            }
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) cin >> r[i] >> c[i];

    visited.resize(n, vector<bool>(n, false));

    for(int i = 0;i < k;i++){
        int re = r[i] - 1;
        int ce = c[i] - 1;
        if(CanGo(re, ce)) Push(re, ce);
        
    }
    BFS();
    cout << total;

    return 0;
}
