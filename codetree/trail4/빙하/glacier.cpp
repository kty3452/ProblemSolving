#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int N, M;
int a[200][200];

vector<vector<bool>> visited;
vector<int> melted_ice_cnt;
queue<pair<int, int>> melted_ice_coor;
queue<pair<int, int>> q;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int Melt(){
    int cnt = 0;
    while(!melted_ice_coor.empty()){
        auto [r, c] = melted_ice_coor.front();
        melted_ice_coor.pop();
        a[r][c] = 0;
        cnt++;
    }
    return cnt;
}


bool CanGo(int r, int c){
    return !visited[r][c] && !a[r][c];
}

bool InRange(int r, int c){
    return r >= 0 && c >= 0 && r < N && c < M;
}

void Push(int r, int c){
    q.push({r, c});
    visited[r][c] = true;
}


void WhatIsMelt(int r, int c){
    for(int i = 0;i < 4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(InRange(nr, nc) && !visited[nr][nc] && a[nr][nc]){
                melted_ice_coor.push({nr, nc});
                visited[nr][nc] = true;
            }
    }
    
}

void BFS(){
    visited.assign(N, vector<bool>(M, false));
    Push(0, 0);
    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();

        for(int i = 0;i < 4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(InRange(nr, nc) && CanGo(nr, nc)){
                Push(nr, nc);
                WhatIsMelt(nr, nc);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    visited.resize(N, vector<bool>(M, false));
    int cnt = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    while(true){
        BFS();
        cnt = Melt();
        if(cnt) melted_ice_cnt.push_back(cnt);
        else break;
    }
    
    cout << melted_ice_cnt.size() << " " << melted_ice_cnt[melted_ice_cnt.size() - 1];

    // Please write your code here.

    return 0;
}
