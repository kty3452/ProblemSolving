#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int n;
int r1, c1, r2, c2;
int visited[100][100]{};
queue<pair<int, int>> q;

void Push(int r, int c, int nr, int nc){
    visited[nr][nc] = visited[r][c] + 1;
    q.push({nr, nc});
}

bool InRange(int r, int c){
    return r >= 0 && c >= 0 && r < n && c < n;
}

bool CanGo(int r, int c){
    return InRange(r, c) && !visited[r][c];
}

void BFS(){
    static int dr[8] = {2, 1, 2, -1, -2, 1, -2, -1};
    static int dc[8] = {1, 2, -1, 2, 1, -2, -1, -2};

    visited[r1 - 1][c1 - 1] = 1;
    q.push({r1 - 1, c1 - 1});

    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();

        for(int i = 0;i < 8;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(CanGo(nr, nc))
                Push(r, c, nr, nc);
        }
    }
}

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    BFS();

    cout << visited[r2 - 1][c2 - 1] - 1;

    return 0;
}
